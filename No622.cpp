// LINK: https://leetcode.com/problems/design-circular-queue

/*
KEY: 用兩個index去記錄目前的head跟tail，底層容器使用vector來實作
*/

class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        myQueue.resize(k, -1);
        headIndex = 0;
        tailIndex = 0;
    }
    
    bool enQueue(int value) {
        // already contain value
        if(myQueue[tailIndex] != -1)
            return false;
        
        // tailIndex reach to the end
        if(tailIndex == myQueue.size() - 1)
        {
            myQueue[tailIndex] = value;
            tailIndex = 0;
        } 
        // normal case
        else
        {
            myQueue[tailIndex] = value;
            tailIndex++;
        }
        return true;
    }
    
    bool deQueue() {
        // doesn't contain value
        if(myQueue[headIndex] == -1)
            return false;
        
        // headIndex reach to the front
        if(headIndex == myQueue.size() - 1)
        {
            myQueue[headIndex] = -1;
            headIndex = 0;
        } 
        // normal case
        else
        {
            myQueue[headIndex] = -1;
            headIndex++;
        }
        return true;
    }
    
    int Front() {
        return myQueue[headIndex];
    }
    
    int Rear() {
        if(tailIndex == 0)
            return myQueue.back();
        else
            return myQueue[tailIndex - 1];
    }
    
    bool isEmpty() {
        for(auto &element : myQueue){
            if(element != -1) return false;
        }
        return true;
    }
    
    bool isFull() {
        for(auto &element : myQueue){
            if(element == -1) return false;
        }
        return true;
    }
    
private:
    vector<int> myQueue;
    int headIndex;
    int tailIndex;
};
