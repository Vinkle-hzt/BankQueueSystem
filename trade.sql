/*
 Navicat MySQL Data Transfer

 Source Server         : banksystem
 Source Server Type    : MySQL
 Source Server Version : 80026
 Source Host           : localhost:3306
 Source Schema         : bank_queue_system

 Target Server Type    : MySQL
 Target Server Version : 80026
 File Encoding         : 65001

 Date: 24/07/2021 10:04:10
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for trade
-- ----------------------------
DROP TABLE IF EXISTS `trade`;
CREATE TABLE `trade`  (
  `trade_num` int NOT NULL AUTO_INCREMENT,
  `card_ID` int NULL DEFAULT NULL,
  `trade_type` int NULL DEFAULT NULL,
  `trade_time` datetime NULL DEFAULT NULL,
  `pre_money` double NULL DEFAULT NULL,
  `cur_money` double NULL DEFAULT NULL,
  `trade_ID` int NULL DEFAULT NULL,
  PRIMARY KEY (`trade_num`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = DYNAMIC;

SET FOREIGN_KEY_CHECKS = 1;
