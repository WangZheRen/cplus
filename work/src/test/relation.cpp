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
TEST(relation, regular_extract_wrap)
{

    /*ptree root;
    read_ini("conf/work.ini", root);
    string url = root.get<string>("relationKg.url");
    cout << url << endl;*/

    // 训练样本
    string s_train = "./data/relation/T_train";
    ifstream in(s_train.c_str());
    ASSERT_FALSE(in.fail());
    string line;

    Relation relation;
    while(getline(in, line, '\n')){
        if (line.empty()){
            continue;
        }
        //vector<RelationMap> vecRelation = relation.regular_extract_single_line(line);
        vector<RelationMap> vecRelation = relation.regular_extract_wrap(line);
        break;
    }

}
