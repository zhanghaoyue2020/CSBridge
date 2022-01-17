# CSBridge

## string length(),size() no difference

https://www.cnblogs.com/lakeone/p/4764577.html


## concatenate two vectors

AB.reserve( A.size() + B.size() );

AB.insert( AB.end(), A.begin(), A.end() )

AB.insert( AB.end(), B.begin(), B.end() )

https://stackoverflow.com/questions/3177241/what-is-the-best-way-to-concatenate-two-vectors


## xxx[1]...xxx[5]

xxxFrom = 1 

xxxTo = 5

xxxBegin = 1

xxxEnd = 6


## s[sSize]=NULL;

accepted:matched = (i != sSize) && (s[i] == p[j] || p[j] == '.');  

error:   matched = (s[i] == p[j] || p[j] == '.') && (i != sSize);
