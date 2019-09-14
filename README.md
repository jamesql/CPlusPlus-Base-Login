# Login-Base-CPP
Basic Login Base w/ C++ &amp; MySQL

# Where to get MySQL Connecter 8 for C++?
- [Click Here!](https://dev.mysql.com/doc/connector-cpp/8.0/en/)

# Connection String
```cpp
"tcp://127.0.0.1:3306", "root", "Password"
```

# Database File (MySQL)

# Convert glob -> std::string function
```cpp
std::string gulp(std::istream *in)
{
    std::string ret;
    char buffer[4096];
    while (in->read(buffer, sizeof(buffer)))
        ret.append(buffer, sizeof(buffer));
    ret.append(buffer, in->gcount());
    return ret;
}
```
