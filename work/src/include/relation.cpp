//
// Created by Zhou,Baochuan on 18/6/6.
//

#include "relation.h"
#include <gtest/gtest.h>

using namespace work;

Relation::Relation() {
    this->init_map_family();
    this->_http = new Http();
}

Relation::~Relation() {
    delete this->_http;
}

// 映射角色关系:关系=>逆向关系
void Relation::init_map_family() {
    string file_path = "./data/relation/D_map_family";
    ifstream in(file_path.c_str());
    ASSERT_FALSE(in.fail());
    string line;
    string relation_name; // 关系名
    string to_reverse_relation_name; // 对应的反向关系名
    vector<string> ret;
    int index = 0;
    while(getline(in, line, '\n')){
        if (index == 0) {
            index++;
            continue;
        }
        split(ret, line, boost::is_any_of("\t"));
        relation_name= ret[0];
        to_reverse_relation_name = ret[1];
        this->_map_family[relation_name] = to_reverse_relation_name;
    }
    in.close();
}


string Relation::added_id_by_kg(const string &name) {
    ptree root;
    read_ini("conf/work.ini", root);
    string url = root.get<string>("relationKg.url") + name;
    string response = conv::between(this->_http->get(url), "UTF-8", "GBK");

    try {
        stringstream str_stream(response);
        ptree root;
        read_json(str_stream, root);
        BOOST_FOREACH(ptree::value_type &v, root.get_child("egl_ret")) {
            return v.second.get_child("_bdbkKgId").get_value<string>();
        }
    } catch (ptree_error &e){
        std::cout<< "error:[" << e.what() << "]url=" << url <<endl;
    }

    return "";
}

// 单行规则提取
vector<RelationMap> Relation::regular_extract_single_line(const string &text) {

    vector<RelationMap> ret;
    stringstream str_stream(text);
    try {
        ptree root;
        read_json(str_stream, root);
        string P1 = root.get_child("lemmaTitle").get_value<string>();
        string L, P2;
        BOOST_FOREACH(ptree::value_type &v1, root.get_child("contentStructured")) {
            if (equals(v1.second.get_child("tag").get_value<string>(), "paragraph")) {
            }

        }
    } catch(ptree_error & e) {
        std::cout<<e.what()<<endl;
    } catch(runtime_error& e) {
        std::cout<<e.what()<<endl;
    }
    return ret;
    /*vector<RelationMap> ret;

    vector<string> vecRole = StringUtil::split(text, "：");
    if (vecRole.size() < 2) {
        return ret;
    }

    vector<string> vecP2 = StringUtil::split(vecRole[1], "，|、");

    for (int i = 0; i < vecP2.size(); i++) {
        if (vecP2[i].empty()) {
            continue;
        }
        RelationMap relationMap;
        relationMap.L = vecRole[0];
        relationMap.P2 = vecP2[i];
        ret.push_back(relationMap);
    }

    return ret;*/
}

// 以下是换行三元关系提取相关功能=====================================
// 获取角色
string Relation::extract_L(ptree::value_type &node) {
    string L;
    string tag = node.second.get_child("tag").get_value<string>();
    if (equals(tag, "paragraph")) {
        return L;
    }

    if (equals(tag, "header")) {
        L = node.second.get_child("title").get_value<string>();
    } else if (equals(tag, "list")) {
        if (equals(node.second.get_child("type").get_value<string>(), "unordered")) {
            // 用于删除html标签正则
            regex rgx("<[a-zA-Z/]*>");
            // 遍历数组中的元素
            BOOST_FOREACH (ptree::value_type& v, node.second.get_child("list")) {
                BOOST_FOREACH (ptree::value_type& v1, v.second) {
                    if (equals(v1.second.get_child("tag").get_value<string>(), "text")) {
                        L = regex_replace(v1.second.get_child("text").get_value<string>(), rgx, "");
                    }
                }
            }
        }
    }
    if (this->_map_family.count(L) > 0) {
        return L;
    }
    return "";
}

// 获取人物名称
vector<map<string, string > > extract_P2(ptree::value_type &node) {
    vector<map<string, string> > ret;

    // filter
    if (!equals(node.second.get_child("tag").get_value<string>(), "paragraph")) {
        return ret;
    }
    if (node.second.get_child("content").empty()) {
        return ret;
    }

    // 遍历数组中的元素
    BOOST_FOREACH (ptree::value_type& v, node.second.get_child("content")) {
        if (equals(v.second.get_child("tag").get_value<string>(), "innerlink")) {
            map<string, string> P2;
            P2[v.second.get_child("lemmaId").get_value<string>()] = v.second.get_child("text").get_value<string>();
            ret.push_back(P2);
        }
    }

    return ret;
}

void Relation::export_file(ptree root, string L, vector<map<string, string> > v_m_P2)
{
    try{
        string id, key;
        for (int i = 0, size = v_m_P2.size(); i < size; i++) {
            for (map<string, string>::iterator iter = v_m_P2[i].begin(); iter != v_m_P2[i].end(); iter++) {
                id = iter->first;
                if (!id.empty()) {
                    id =  added_id_by_kg(iter->second);
                }
                // 已有的关系就不做导出
                key = root.get<string>("lemmaId") + "_" + id;
                if (this->_map_cache_had_relation.count(key) > 0) {
                    continue;
                } else {
                   this->_map_cache_had_relation[key] = key;
                }

                cout << root.get<string>("lemmaId") << "\t" << root.get<string>("lemmaTitle") << "\t";
                cout << root.get<string>("url") << "\t" << L << "\t";
                cout << iter->second << "\t" << id << "\t" << "\t";
                cout << "https://baike.baidu.com/item/" << iter->second << "/" << id << endl;
            }
        }
    } catch (exception &e) {
        cout << e.what() << endl;
    }
}
vector<RelationMap> Relation::regular_extract_wrap(const string &text) {
    vector<RelationMap> ret;
    if (text.empty()) {
        return ret;
    }

    stringstream str_stream(text);
    try {
        ptree root;
        read_json(str_stream, root);
        string L, P2;
        vector<map<string, string> > v_m_P2;
        BOOST_FOREACH(ptree::value_type &v, root.get_child("contentStructured")) {
           if (!equals(v.second.get_child("tag").get_value<string>(), "paragraph")) {
               L = this->extract_L(v);
           } else {
               if (!L.empty()) {
                   v_m_P2 = extract_P2(v);
                   if (v_m_P2.size() > 0) {
                       export_file(root, L, v_m_P2);
                   }
               }
           }
        }
    } catch(ptree_error & e) {
        std::cout<<e.what() <<endl;
    } catch(runtime_error& e) {
        std::cout<<e.what()<<endl;
    }
    return ret;
}
