-- phpMyAdmin SQL Dump
-- version 4.9.0.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Oct 08, 2019 at 10:17 AM
-- Server version: 10.4.6-MariaDB
-- PHP Version: 7.3.9

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `healthylifestyle`
--

-- --------------------------------------------------------

--
-- Table structure for table `doctor_info`
--

CREATE TABLE `doctor_info` (
  `Name` varchar(30) NOT NULL,
  `designation` text NOT NULL,
  `Phone Number` varchar(30) NOT NULL,
  `hospital Name` varchar(30) NOT NULL,
  `address` text NOT NULL,
  `hospital Phone` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `doctor_info`
--

INSERT INTO `doctor_info` (`Name`, `designation`, `Phone Number`, `hospital Name`, `address`, `hospital Phone`) VALUES
('', '', '', '', '', ''),
('abc', 'xyz', '123', 'xyz', 'pqr', '345');

-- --------------------------------------------------------

--
-- Table structure for table `medical_info`
--

CREATE TABLE `medical_info` (
  `Systolic` varchar(20) NOT NULL,
  `Diastolic` varchar(20) NOT NULL,
  `Respiratory_Rate` varchar(20) NOT NULL,
  `Body_Temparature` varchar(20) NOT NULL,
  `Blood_Sugar` varchar(20) NOT NULL,
  `Himoglobin` varchar(20) NOT NULL,
  `Rbc` varchar(20) NOT NULL,
  `Wbc` varchar(20) NOT NULL,
  `Platelets` varchar(20) NOT NULL,
  `Tsh` varchar(20) NOT NULL,
  `Hdl` varchar(20) NOT NULL,
  `Ldl` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `medical_info`
--

INSERT INTO `medical_info` (`Systolic`, `Diastolic`, `Respiratory_Rate`, `Body_Temparature`, `Blood_Sugar`, `Himoglobin`, `Rbc`, `Wbc`, `Platelets`, `Tsh`, `Hdl`, `Ldl`) VALUES
('', '', '', '', '', '', '', '', '', '', '', '');

-- --------------------------------------------------------

--
-- Table structure for table `record`
--

CREATE TABLE `record` (
  `operation dates` varchar(20) NOT NULL,
  `operation reports` text NOT NULL,
  `pregnancy outcomes` varchar(30) NOT NULL,
  `any complications` varchar(30) NOT NULL,
  `growth Rate` varchar(30) NOT NULL,
  `intellectual development` varchar(30) NOT NULL,
  `Smoking` varchar(30) NOT NULL,
  `alcohol consumption` varchar(30) NOT NULL,
  `common family diseases` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `record`
--

INSERT INTO `record` (`operation dates`, `operation reports`, `pregnancy outcomes`, `any complications`, `growth Rate`, `intellectual development`, `Smoking`, `alcohol consumption`, `common family diseases`) VALUES
('4/4/23', 'sometimes', 'not needed', 'null', 'normal', 'avarage', 'sometimes', 'no', 'diabatics');

-- --------------------------------------------------------

--
-- Table structure for table `todolist`
--

CREATE TABLE `todolist` (
  `Username` text NOT NULL,
  `task1` text NOT NULL,
  `task2` text NOT NULL,
  `task3` text NOT NULL,
  `task4` text NOT NULL,
  `task5` text NOT NULL,
  `task6` text NOT NULL,
  `task7` text NOT NULL,
  `task8` text NOT NULL,
  `task9` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `userinformation`
--

CREATE TABLE `userinformation` (
  `Name` text NOT NULL,
  `Age` int(11) NOT NULL,
  `Gender` text NOT NULL,
  `Height` double NOT NULL,
  `Weight` int(11) NOT NULL,
  `Username` text NOT NULL,
  `Password` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `userinformation`
--

INSERT INTO `userinformation` (`Name`, `Age`, `Gender`, `Height`, `Weight`, `Username`, `Password`) VALUES
('adiba', 19, 'Female', 5.1, 45, 'adiba23', '23452'),
('vabna', 21, 'Female', 5.3, 51, 'vabna404', '1468'),
('Moon', 20, 'Female', 5.2, 53, 'moons4', '2467'),
('sabrina', 21, 'Female', 5.1, 47, 'sabrin94', '20204'),
('abc', 13, 'Male', 4.9, 43, 'abcdef', '23456'),
('s', 1, 'Female', 1.5, 2, 'ssss', '23456'),
('avc', 2, 'Female', 2.5, 7, 'avc', '234'),
('q', 2, 'Female', 3.1, 3, 'qqq', '333'),
('qqq', 3, 'Female', 3, 5, 'qqqqa', '234'),
('zain', 31, 'Female', 5.4, 67, 'zain67', '12345'),
('dina', 20, 'Female', 5, 52, 'dina234', '23456'),
('s', 2, 'Male', 3.2, 32, 's3', '345'),
('s', 3, 'Male', 2.1, 21, 'sws', '231'),
('naima', 21, 'Female', 5.3, 53, 'naima321', '321naima'),
('z', 1, 'Male', 1.5, 5, 'zzz', '234'),
('e', 4, 'Male', 3.2, 24, 'eeee', '456'),
('sab', 2, 'Male', 3.1, 34, 'sabbb', '234');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `doctor_info`
--
ALTER TABLE `doctor_info`
  ADD PRIMARY KEY (`Phone Number`,`hospital Phone`);

--
-- Indexes for table `medical_info`
--
ALTER TABLE `medical_info`
  ADD PRIMARY KEY (`Systolic`,`Diastolic`,`Respiratory_Rate`,`Body_Temparature`,`Blood_Sugar`,`Himoglobin`,`Rbc`,`Wbc`,`Platelets`,`Tsh`,`Hdl`,`Ldl`) USING BTREE,
  ADD UNIQUE KEY `Systolic` (`Systolic`),
  ADD UNIQUE KEY `Diastolic` (`Diastolic`),
  ADD UNIQUE KEY `Respiratory_Rate` (`Respiratory_Rate`),
  ADD UNIQUE KEY `Body_Temparature` (`Body_Temparature`),
  ADD UNIQUE KEY `Blood_Sugar` (`Blood_Sugar`),
  ADD UNIQUE KEY `Rbc` (`Rbc`),
  ADD UNIQUE KEY `Wbc` (`Wbc`),
  ADD UNIQUE KEY `Platelets` (`Platelets`),
  ADD UNIQUE KEY `Tsh` (`Tsh`),
  ADD UNIQUE KEY `Hdl` (`Hdl`),
  ADD UNIQUE KEY `Ldl` (`Ldl`),
  ADD UNIQUE KEY `Himoglobin` (`Himoglobin`),
  ADD UNIQUE KEY `Systolic_2` (`Systolic`);

--
-- Indexes for table `record`
--
ALTER TABLE `record`
  ADD PRIMARY KEY (`operation dates`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
