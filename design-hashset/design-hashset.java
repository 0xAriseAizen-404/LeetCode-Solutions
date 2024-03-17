class MyHashSet {
    Set<Integer> mySet;
    public MyHashSet() {
        mySet = new HashSet<>();
    }
    
    public void add(int key) {
        mySet.add(key);
    }
    
    public void remove(int key) {
        mySet.remove(key);
    }
    
    public boolean contains(int key) {
        return mySet.contains(key);
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */