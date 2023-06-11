class SnapshotArray {
public:
    vector<map<int,int>>mapping;
    int sid = 0;
    SnapshotArray(int length) {
        mapping.resize(length);
        for(int i = 0;i< length;i++){
            mapping[i][0] = 0;
        }
    }
    
    void set(int index, int val) {
        mapping[index][sid] = val;
    }
    
    int snap() {
        sid++;
        return sid - 1;
    }
    
    int get(int index, int snap_id) {
        while(snap_id >= 0 && mapping[index].find(snap_id) == mapping[index].end()){
            snap_id--;
            if(snap_id == -1){
                return 0;
            }
        }
        return mapping[index][snap_id];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
