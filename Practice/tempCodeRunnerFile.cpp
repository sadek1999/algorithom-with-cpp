
    for (int i = 0; i < n; i++)
    {
       cout << i ;
        for (auto x : adj_list[i])
        {
            cout << x.first << " " << x.second ;
        }
        cout << endl;
    }