#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int getFirstPriority(int priority_num[10]){
    for (int i=9; i>0; --i){
        if(priority_num[i] != 0){
            return i;
        }
    }
}

int solution(vector<int> priorities, int location) {
    int priority_num[10] = { 0, };
    queue<int> waiting_queue;
    vector<int> print_order;
    int priority;
    
    for (int i=0; i<priorities.size(); ++i){
        waiting_queue.push(i);
        priority_num[priorities[i]]++;
    }
    
    
    while(!waiting_queue.empty()){
        priority = getFirstPriority(priority_num);
        if(priorities[waiting_queue.front()] == priority){
            print_order.push_back(waiting_queue.front());
            waiting_queue.pop();
            priority_num[priority]--;
        }
        else{
            waiting_queue.push(waiting_queue.front());
            waiting_queue.pop();
        }
    }
    
    for(int i=0; i<print_order.size(); ++i){
        if(print_order[i] == location){
            return i + 1;
        }
    }
}