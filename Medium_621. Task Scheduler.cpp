//2022-05-19
//greedy
//reference1 : https://leetcode.com/problems/task-scheduler/discuss/104500/Java-O(n)-time-O(1)-space-1-pass-no-sorting-solution-with-detailed-explanation
//reference2 : https://leetcode.com/problems/task-scheduler/discuss/104504/C%2B%2B-8lines-O(n)
//time  : O(n)
//space : O(26)
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        int letter[26]={0};
        int max_freq=0;
        int number_of_max_freq=0;
        
        for(auto& i:tasks)
        {
            ++letter[i-'A'];
            if(max_freq<letter[i-'A'])
            {
                max_freq=letter[i-'A'];
                number_of_max_freq=1;
            }
            else if(max_freq==letter[i-'A'])
            {
                ++number_of_max_freq;
            }
        }
        //printf("%d %d \n",max_freq,number_of_max_freq);
        
        if(number_of_max_freq-1>=n) return tasks.size();
        
        int region_len=(max_freq-1)*(n+1);
        int res=region_len+number_of_max_freq;
        
        return (tasks.size()>res) ? tasks.size() : res;
    }
};

//2024-02-20
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        vector<int> freqs(26, 0);
        for (char c : tasks) ++freqs[c - 'A'];

        priority_queue<int> maxHeap;
        for (int freq : freqs)
        {
            if(freq > 0) maxHeap.push(freq);
        }
                
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> waiting;
        int time = 0;
        while (!(maxHeap.empty() && waiting.empty()))
        {
            //cout << maxHeap.size() << " " << waiting.size() << endl;
            while (!waiting.empty() && waiting.top()[0] <= time)
            {
                int freq = waiting.top()[1];
                waiting.pop();
                maxHeap.push(freq);
            }

            if (!maxHeap.empty())
            {
                int freq = maxHeap.top() - 1;
                maxHeap.pop();

                if (freq > 0) waiting.push({ time + n + 1, freq });
            }

            ++time;
        }
        
        return time;
    }
};
