//
// Created by Zhou,Baochuan on 18/6/25.
//

#include "common.h"
#include "relation.h"

using namespace work;

int main(int argc, char** argv) {
    // 训练样本
    string s_train = "./data/relation/T_train";
    ifstream in(s_train.c_str());
    string line, url, id;
    ptree root;

    Relation relation;
    // 先初始化id和url的映射关系
    while(getline(in, line, '\n')){
        if (line.empty()){
            continue;
        }
        try {
            stringstream str_stream(line);
            read_json(str_stream, root);
            id = root.get_child("lemmaId").get_value<string>();
            url = root.get_child("url").get_value<string>();
            relation.add_id_url(id, url);
        } catch(ptree_error & e) {
        }
    }
    in.clear();
    in.seekg(0, ios::beg);

    while(getline(in, line, '\n')){
        if (line.empty()){
            continue;
        }
        relation.regular_extract_single_line(line);
        relation.regular_extract_wrap(line);
    }
    in.close();
    return 0;
}