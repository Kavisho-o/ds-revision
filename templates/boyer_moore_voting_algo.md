## majority element II template (n/3 Boyer-Moore)
- tc: O(n)
- sc: O(1)


## pattern
- "majority element n/3"
- "more than n/3 times"
- "find frequent elements"
- "at most 2 elements"
- "Boyer Moore extension"


## algo
- Maintain two candidates and two counters
- First pass: find potential candidates
- If number matches candidate, increment count
- If count becomes zero, replace candidate
- Otherwise decrement both counters
- Second pass: count frequency of candidates
- Return candidates having frequency > n/3


## black box
vector<int> majorityElement(vector<int>& nums) {

    int candidate1 = 0, candidate2 = 0;
    int count1 = 0, count2 = 0;

    for (int num : nums){

        if (num == candidate1) count1++;

        else if (num == candidate2) count2++;

        else if (count1 == 0){
            candidate1 = num;
            count1 = 1;
        }

        else if (count2 == 0){
            candidate2 = num;
            count2 = 1;
        }

        else{
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;

    for (int num : nums){
        if (num == candidate1) count1++;
        else if (num == candidate2) count2++;
    }

    vector<int> ans;

    if (count1 > nums.size()/3) ans.push_back(candidate1);
    if (count2 > nums.size()/3) ans.push_back(candidate2);

    return ans;
}