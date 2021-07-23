/*
 Navicat MySQL Data Transfer

 Source Server         : database1
 Source Server Type    : MySQL
 Source Server Version : 80020
 Source Host           : localhost:3306
 Source Schema         : bank_queue_system

 Target Server Type    : MySQL
 Target Server Version : 80020
 File Encoding         : 65001

 Date: 23/07/2021 14:16:30
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for admin
-- ----------------------------
DROP TABLE IF EXISTS `admin`;
CREATE TABLE `admin`  (
  `ID` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `password` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`ID`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of admin
-- ----------------------------
INSERT INTO `admin` VALUES ('admin', '21232f297a57a5a743894a0e4a801fc3');

-- ----------------------------
-- Table structure for card
-- ----------------------------
DROP TABLE IF EXISTS `card`;
CREATE TABLE `card`  (
  `card_ID` int NOT NULL,
  `user_ID` int NULL DEFAULT NULL,
  `money` double NULL DEFAULT NULL,
  PRIMARY KEY (`card_ID`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of card
-- ----------------------------

-- ----------------------------
-- Table structure for trade
-- ----------------------------
DROP TABLE IF EXISTS `trade`;
CREATE TABLE `trade`  (
  `card_ID` int NOT NULL,
  `trade_type` int NULL DEFAULT NULL,
  `pre_money` double NULL DEFAULT NULL,
  `cur_money` double NULL DEFAULT NULL,
  PRIMARY KEY (`card_ID`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of trade
-- ----------------------------

-- ----------------------------
-- Table structure for user
-- ----------------------------
DROP TABLE IF EXISTS `user`;
CREATE TABLE `user`  (
  `user_ID` int NOT NULL AUTO_INCREMENT,
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `vip` int NULL DEFAULT NULL,
  PRIMARY KEY (`user_ID`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of user
-- ----------------------------
INSERT INTO `user` VALUES (10001, '张三', 0);
INSERT INTO `user` VALUES (10002, '李四', 1);
INSERT INTO `user` VALUES (10003, '王五', 2);
INSERT INTO `user` VALUES (10006, 'vinkle', 0);
INSERT INTO `user` VALUES (10009, 'jony', 0);
INSERT INTO `user` VALUES (10010, 'mike', 0);
INSERT INTO `user` VALUES (10011, 'jerry', 0);

SET FOREIGN_KEY_CHECKS = 1;
