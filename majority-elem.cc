// https://www.interviewbit.com/problems/majority-element/

int Solution::majorityElement(const vector<int> &A) {
    map<int, int> m;
    int maxelem;
    
    for (auto& a: A) {
        if (m.count(a)) {
            m[a]++;
        }
        else {
            m[a] = 1;
        }
        
        if (m[a] > floor(A.size() / 2)) {
            maxelem = a;
        }
    }
    
    return maxelem;
}
