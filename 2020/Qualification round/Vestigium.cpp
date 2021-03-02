#include <bits/stdc++.h>

using namespace std;


void trace(vector<vector<int>> vec, int size)
{
    int sum=0;
    int k=1;


    int rowRepeatCounts=0;
    int colRepeatCounts =0;

    for(int i=0; i< size; i++)
    {
        bool rowHasDups = false;
        bool colHasDups = false;
        
        multiset<int> row;
        multiset<int> col;

        for(int j=0; j<size; j++)
        {
            if(i==j)
            {
                sum += vec[i][j];
            }
            int rowc = vec[i][j];
            int colc = vec[j][i];

            if(row.count(rowc) ==1){
                rowHasDups = true;
            }

            if(col.count(colc)){
                colHasDups = true;
            }   

            row.insert(rowc);
            col.insert(colc);
        }

        if(rowHasDups){
            rowRepeatCounts++;
        }

        if(colHasDups){
            colRepeatCounts++;
        }
    }
    cout << "Case #"<<k<<": "<<sum<<" "<<rowRepeatCounts<<" "<<colRepeatCounts <<endl;
    k++;
}


void solve() 
{
    int n;
    cin>>n;
    int val;
    vector<vector<int>> mtx;
    
    for(int i=0; i<n;i++)
    {
        vector<int> temp;

        for(int j=0; j<n;j++)
        {
            cin>>val;
            temp.push_back(val);
        }
        mtx.push_back(temp);
        temp.clear();
    }

    trace(mtx, n);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;     
}
