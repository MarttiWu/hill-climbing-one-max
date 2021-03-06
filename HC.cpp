//
//  HC.cpp
//  search
//
//  Created by WU,MENG-TING on 2020/7/1.
//  Copyright © 2020 WU,MENG-TING. All rights reserved.
//

#include "HC.hpp"

HC::HC():bits(10),iter(5){
    vector<int> temp1(bits,0);
    vector<vector<int> > temp2(iter,vector<int>(bits,0));
    vector<int> temp3(iter,0);
    bitstr = temp1;
    best_bitstr = temp1;
    record_bitstr = temp2;
    record_value = temp3;
}

HC::HC(int bits,int iter):bits(bits),iter(iter){
    vector<int> temp1(bits,0);
    vector<vector<int> > temp2(iter,vector<int>(bits,0));
    vector<int> temp3(iter,0);
    bitstr = temp1;
    best_bitstr = temp1;
    record_bitstr = temp2;
    record_value = temp3;
}

int HC::FitnessFunction(vector<int> str){
    int sum=0;
    for (int i=0;i<str.size();i++)
        sum+=str[i];
    return sum;
}

void HC::run(){
    init_point();
    best_value = value = FitnessFunction(bitstr);
    best_bitstr = bitstr;
    record_bitstr[0] = best_bitstr;
    record_value[0] = best_value;
    int it=1;
    //stopping condition
    while (it<iter&&best_value<bits){
        if (test_right()>=best_value){
            go_right();
        }
        else if (test_left()>=best_value){
            go_left();
        }
        else
            break;
        
        value = FitnessFunction(bitstr);
        
        if (value>best_value){
            best_value = value;
            best_bitstr = bitstr;
        }
        
        record_bitstr[it] = best_bitstr;
        record_value[it] = best_value;
        it++;
    }
    for (int i=it;i<record_value.size();i++){
        record_bitstr[i] = best_bitstr;
        record_value[i] = best_value;
    }
}

void HC::init_point(){
    for (int i=bits-1;i>=0;i--){
        bitstr[i] = rand()%2;
    }
}

int HC::test_right(){
    int s=STEP; //step right 2^(STEP)
    vector<int> tempstr;
    tempstr = bitstr;
    while(tempstr[s]==1){
        tempstr[s]=0;
        s++;
    }
    tempstr[s]=1;
    return FitnessFunction(tempstr);
}
int HC::test_left(){
    int s=STEP; //step left 2^(STEP)
    vector<int> tempstr;
    tempstr = bitstr;
    while(tempstr[s]==0){
        tempstr[s]=1;
        s++;
    }
    tempstr[s]=1;
    return FitnessFunction(tempstr);
}

void HC::go_right(){
    int i=STEP; //step right 2^(STEP)
    while(bitstr[i]==1){
        bitstr[i]=0;
        i++;
    }
    bitstr[i]=1;
}

void HC::go_left(){
    int i=STEP; //step left 2^(STEP)
    while(bitstr[i]==0){
        bitstr[i]=1;
        i++;
    }
    bitstr[i]=0;
}
