/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.

Subscribe to see which companies asked this question
*/

//I think it too much.
//Just one way from 0 - gas.end()
//Using greedy method to solve it. Firstly set two variables sum, total.
//sum represents the available of current station. total represents the available of this circular route.
//sum += gas[i] - cost[i], if it is less than 0, means this station is not available, so change the start station to current station.
//set sum = 0; start point = current station.
//total += sum; means the cost of total circular route. if total less than 0, means this circular is not available.
//O(n) time , O(1) space

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int sum = 0;
        int j = 0;
        for(int i = 0; i < gas.size(); i++) {
            sum += (gas[i] - cost[i]);
            total += sum;
            if(sum < 0) {
                j = i + 1;
                sum = 0;
            }
        }
        return total >= 0 ? j : -1;
    }
};