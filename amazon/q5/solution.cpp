int minKyepadClickCount(string text ){

    map<char,int> m;
    for( int i = 0 ; i < text.length() ; ++i ){
        m[text[i]]++;
    }

    vector<int> v;
    for( auto p = m.begin() ; p != m.end() ; ++p ){
        v.push_back(p->second);
    }

    sort(v.rbegin(),v.rend());
    int ans = 0;

    int i = 0;
    while( i < v.size() ){

        if( i < 9 ){
            ans += v[i];
            ++i;
        }
        else if( i < 18 ){
            ans += 2*v[i];
            ++i;
        }
        else{
            ans += 3*v[i];
            ++i;
        }

    }

    return ans;

}
