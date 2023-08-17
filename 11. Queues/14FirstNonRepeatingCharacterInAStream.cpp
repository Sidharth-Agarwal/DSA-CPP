#include<iostream>
#include<queue>
#include<string>
#include<unordered_map>

using namespace std;

string nonRepeatingStream(string input)
{
    queue<int> q;
    unordered_map<char, int> count;

    string ans = "";

    for (int i = 0; i < input.length();i++)
    {   
        char front = input[i];

        //increasing the count
        count[front]++;

        // pushing the element into the queue
        q.push(front);

        while(!q.empty())
        {
            if(count[q.front()] > 1)
            {
                q.pop();
            }

            else
            {
                ans.push_back(q.front());
                break;
            }
        }

        if(q.empty())
        {
            ans.push_back('#');
        }
    }

    return ans;
}

int main()
{
    string input = "aabc";

    string ans = nonRepeatingStream(input);
    cout << ans;
}