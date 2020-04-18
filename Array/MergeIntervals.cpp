vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> result;
    bool pinnedStart = false;
    bool inserted = false;
    
    for(Interval &i : intervals){
        if(inserted){
            result.push_back(i);
            continue;
        }

        if(!pinnedStart && newInterval.start < i.start){
            pinnedStart = true;
        } else if(!pinnedStart && newInterval.start < i.end){
            pinnedStart = true;
            newInterval.start = i.start;
        } else if(!pinnedStart) {
            result.push_back(i);
            continue;
        }
        
        if(newInterval.end < i.start){
            result.push_back(newInterval);
            result.push_back(i);
            inserted = true;
        } else if(newInterval.end < i.end){
            newInterval.end = i.end;
            result.push_back(newInterval);
            inserted = true;
        }
    }
    
    if(!inserted){
        result.push_back(newInterval);
    }
    
    return result;
}