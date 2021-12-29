#include "SkipList.h"
#include <iostream>
using namespace std;

SLNode::SLNode(int k, int level){
    key = k;
    forward = new SLNode* [level+1];

    memset(forward, 0, sizeof(SLNode*) * (level+1));
}

void SLNode::setForward(int idx, SLNode* node){
    forward[idx] = node;
}

int SLNode::getKey(){
    return key;
}

SLNode* SLNode::getForward(int idx){
    return forward[idx];
}

SkipList::SkipList(int max, float p){ 
    MAXLVL = max;    
    P = p; //P = probability
    level = 0;
    header = new SLNode(-1, MAXLVL);
    count = 0;
}

int SkipList::randomLevel(){
    float r = (float)rand() / RAND_MAX;
    int lvl = 0;
    //當random出的數字小於probability且level尚未高於maxlevel，則可以增加層數
    //舉例來說若我的P = 0.9，將會從0-1分成<0.9與>=0.9的小數，意味著我有九成的機會增加level
    //同理，可將P傳入成0.5或是0.1...等等的機率
    while(r < P && lvl < MAXLVL){ 
        lvl++;
        r = (float)rand() / RAND_MAX;
        count ++;
    }
    return lvl;
}

SLNode* SkipList::createSLNode(int key, int level){
    SLNode* n = new SLNode(key, level);
    return n;
}

void SkipList::Insert(int key){
    SLNode* current = header;

    SLNode* update[MAXLVL + 1];
    memset(update, 0, sizeof(SLNode*) * (MAXLVL+1));
    for(int i = level ; i >= 0 ; i--){
        while(current->getForward(i) != NULL && (current->getForward(i))->getKey() < key)
            current = current->getForward(i);
        update[i] = current;
    }

    current = current->getForward(0);

    if (current == NULL || current->getKey() != key){
        int rlevel = randomLevel();
        if(rlevel > level){
            for(int i = level + 1 ; i < rlevel + 1 ; i++)
                update[i] = header;

            level = rlevel;
        }

        SLNode* n = createSLNode(key, rlevel);

        for(int i = 0 ; i <= rlevel ; i++){
            n->setForward(i, update[i]->getForward(i));
            update[i]->setForward(i, n);
        }
    }
}

void SkipList::Delete(int key){
    SLNode* current = header;

    SLNode* update[MAXLVL + 1];
    memset(update, 0, sizeof(SLNode*) * (MAXLVL + 1));

    for(int i = level ; i >= 0 ; i--){
        while(current->getForward(i) != NULL && (current->getForward(i))->getKey() < key)
            current = current->getForward(i);
        update[i] = current;
    }

    current = current->getForward(0);

    if(current != NULL and current->getKey() == key){
        for(int i = 0 ; i <= level ; i++){
            if(update[i]->getForward(i) != current)
                break;

            update[i]->setForward(i, current->getForward(i));
        }

        while(level > 0 && header->getForward(level) == 0)
            level--;
    }
}

void SkipList::Search(int key){
    SLNode* current = header;

    for(int i = level ; i >= 0 ; i--){
        while(current->getForward(i) && (current->getForward(i))->getKey() < key)
            current = current->getForward(i);

    }

    current = current->getForward(0);
}

