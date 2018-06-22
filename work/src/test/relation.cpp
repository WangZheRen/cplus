//
// Created by Zhou,Baochuan on 18/6/6.
//

#include "common.h"
#include "relation.h"
#include <gtest/gtest.h>


using namespace work;

void print_ptree_node(ptree node, int spaceWidth){
    BOOST_FOREACH(ptree::value_type const &v, node) {
        if (!v.second.get_value<string>(v.first).empty()) {
            cout << left << setw(spaceWidth) << v.first << "\t" << v.second.get_value(v.first) << endl;
        } else{
            spaceWidth += 1;
            print_ptree_node(v.second, spaceWidth);
        }

    }

}

// 人物关系规则提取
TEST(relation, regular_extract)
{

    /*ptree root;
    read_ini("conf/work.ini", root);
    string url = root.get<string>("relationKg.url");
    cout << url << endl;*/
    //BOOST_LOG_TRIVIAL(trace)<<"A trace severity message";

    // 训练样本
    string s_train = "./data/relation/T_train";
    ifstream in(s_train.c_str());
    ASSERT_FALSE(in.fail());
    string line;

    Relation relation;
    vector<RelationMap> vecRelation;
    while(getline(in, line, '\n')){
        if (line.empty()){
            continue;
        }
        vecRelation = relation.regular_extract_single_line(line);
        vecRelation = relation.regular_extract_wrap(line);
        break;
    }

}
