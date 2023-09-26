class MyCalendar {
    
public:
vector<pair<int,int>>v; 
    
    MyCalendar() {
   
    }
    pair<int,int> givePair(int start, int end){
            pair<int, int> p;
            p.first=start;
            p.second=end;
            return p;
    }
    
    bool book(int start, int end) {
   
         if(v.size()==0){
            v.push_back(givePair(start,end));
            return true;
        }
        
        
        if(start<=v[0].first && end <= v[0].first){
            v.insert(v.begin(),givePair(start,end) );
            return true;
            
        }
        else if(start>=v[v.size()-1].first && start>=v[v.size()-1].second){
            v.push_back(givePair(start,end));
            return true;
            
        }
        else{
   
            for(int i=0;i<v.size()-1;i++){
                if(start>v[i].first && start<v[i+1].first ){
                    if(start>=v[i].second && end<=v[i+1].first){
                         v.insert(v.begin()+i+1,givePair(start,end) );
                        return true;
                        
                    }
                }
            }
            
            return false;
        }
    
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
