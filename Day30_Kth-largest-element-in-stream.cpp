class KthLargest {
public:
    
    //min-heap(minimum values are at the top) priority_queue
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    
    KthLargest(int k, vector<int>& nums) 
    {
        K=k;
        
        //put elements into the pq
        for(int it:nums)
        {
            pq.push(it);
            
            //since we want kth larget element, we pop elements from pq if its size > K
            if(pq.size()>K)
                pq.pop();
        }
    }
    
    int add(int val) 
    {   
        pq.push(val);
        
        //we only keep kth larget elements and pop other element
        if(pq.size() > K)
            pq.pop();
        
        //top most element will be the ans
        return pq.top();       
    }
};
