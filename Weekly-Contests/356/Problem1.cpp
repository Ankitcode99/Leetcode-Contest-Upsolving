// Number of Employees Who Met the Target

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int count=0;
        for(int x: hours){
            count += (x>=target);
        }
        return count;
    }
};