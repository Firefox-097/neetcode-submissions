class MedianFinder {
public:
    priority_queue<int > left;
    priority_queue<int , vector<int>, greater<int>> right;
    MedianFinder() {
    }
    void addNum(int num) {
        left.push(num);
        if(!right.empty() && left.top()>right.top()){
            int x=left.top();
            right.push(x);
            left.pop();
        }
        if(left.size() > right.size()+1){
            int x=left.top();
            right.push(x);
            left.pop();
        }
        if(left.size() < right.size()){
            int x=right.top();
            left.push(x);
            right.pop();
        }
    }
    double findMedian() {
        if(left.size()>right.size()) return left.top();
        return (left.top()+right.top())/2.0;
    }
};
