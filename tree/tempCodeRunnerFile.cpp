    sort(result.begin(), result.end(), compare_tuple);
    for (tuple<unsigned int, unsigned int> temp : result)
    {
        cout << get<0>(temp) <<"  "<<get<1>(temp)<<endl;
    }