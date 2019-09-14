# Login-Base-CPP
Basic Login Base w/ C++ &amp; MySQL

# Where to get MySQL Connecter 8 for C++?
- [Click Here!](https://dev.mysql.com/doc/connector-cpp/8.0/en/)

# Connection String
```cpp
"tcp://127.0.0.1:3306", "root", "Password"
```

# Database File (MySQL)
``sql
-- --------------------------------------------------------
-- Host:                         127.0.0.1
-- Server version:               5.7.18-log - MySQL Community Server (GPL)
-- Server OS:                    Win64
-- HeidiSQL Version:             9.4.0.5125
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;


-- Dumping database structure for cpptest
CREATE DATABASE IF NOT EXISTS `cpptest` /*!40100 DEFAULT CHARACTER SET utf8 */;
USE `cpptest`;

-- Dumping structure for table cpptest.user
CREATE TABLE IF NOT EXISTS `user` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `un` varchar(50) NOT NULL DEFAULT '0',
  `password` varchar(999) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
```


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
