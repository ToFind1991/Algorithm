//
//  CommonStructs.hpp
//  algorithm
//
//  Created by shiwei on 2018/9/1.
//

#ifndef CommonStructs_hpp
#define CommonStructs_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <functional>
#include "BinaryTree.hpp"


using namespace std;

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

struct Point{
    int x;
    int y;
};

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
    
    static ListNode *createList(vector<int> vals){
        ListNode *head = nullptr;
        ListNode *last = nullptr;
        for (auto iter = vals.begin(); iter != vals.end(); iter ++) {
            ListNode *node = new ListNode(*iter);
            
            if (head == nullptr) {
                head = node;
            }else{
                last->next = node;
            }
            last = node;
        }
        
        return head;
    }
    
    static void printList(ListNode *list){
        if (list == nullptr) {
            printf("list is empty!\n");
            return;
        }
        
        printf("%d",list->val);
        list = list->next;
        
        while (list) {
            printf("->%d",list->val);
            list = list->next;
        }
        
        printf("\n");
    }
};


#pragma mark - 调试函数

template<class T>
static void printVector(vector<T> &vector){
    for (auto &val : vector){
        cout<<val<<endl;
    }
}

template<class T>
static void printVectorOneLine(vector<T> &vector){
    for (auto &val : vector){
        cout<<val<<" ";
    }
    cout<<endl;
}

template<class T>
static void printTwoDVector(vector<vector<T>> & twoDVector){
    for (auto iter = twoDVector.begin(); iter != twoDVector.end(); iter++) {
        printVectorOneLine(*iter);
    }
}

#pragma mark - 辅助工具函数

extern void readFile(string &path, const function<void(string &)>& handleLine);


#pragma mark - 经典常用函数

/** 是否素数 */
extern bool isPrimeNum(int num);

/**
 * 将数组切割为两部分，使得左边<=中间数<右边，返回这个中间数的索引;
 * 这个函数是快排、求中位数、第k小的数等的辅助工具
 */
extern int partion(vector<int> &nums, int start, int end);

/** 第k小的数 */
extern int kthSmallest(int k, vector<int> &nums);

/** 第k大的数 */
extern int kthLargestElement(int n, vector<int> &nums);

//TODO: topK问题

/** 查找一个数在有序数组中的范围，考虑到不存在和重复的问题；进化版的二分法 */
extern vector<int> searchRange(vector<int> &A, int target);

#endif /* CommonStructs_hpp */
