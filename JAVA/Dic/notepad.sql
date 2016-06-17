/*
Navicat MySQL Data Transfer

Source Server         : 本地
Source Server Version : 50520
Source Host           : localhost:3306
Source Database       : mysql

Target Server Type    : MYSQL
Target Server Version : 50520
File Encoding         : 65001

Date: 2016-06-16 22:28:43
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `notepad`
-- ----------------------------
DROP TABLE IF EXISTS `notepad`;
CREATE TABLE `notepad` (
  `English` varchar(255) NOT NULL,
  `Chinese` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`English`)
) ENGINE=InnoDB DEFAULT CHARSET=gbk;

-- ----------------------------
-- Records of notepad
-- ----------------------------
