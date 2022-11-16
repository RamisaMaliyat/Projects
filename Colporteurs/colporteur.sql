-- phpMyAdmin SQL Dump
-- version 4.9.0.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Mar 24, 2021 at 08:45 AM
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
-- Database: `colporteur`
--

-- --------------------------------------------------------

--
-- Table structure for table `contactus`
--

CREATE TABLE `contactus` (
  `id` int(11) NOT NULL,
  `Name` varchar(255) DEFAULT NULL,
  `Email` varchar(50) NOT NULL,
  `Message` varchar(1000) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `team`
--

CREATE TABLE `team` (
  `Name` varchar(255) NOT NULL,
  `ID` int(11) NOT NULL,
  `Email` varchar(50) NOT NULL,
  `Image` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `team`
--

INSERT INTO `team` (`Name`, `ID`, `Email`, `Image`) VALUES
('Ramisa Maliyat', 180104079, '180104079@aust.edu', 'iamges/resized.jpg'),
('Sadia Sultana', 180104094, '180104094@aust.edu', 'iamges/resized.jpg');

-- --------------------------------------------------------

--
-- Table structure for table `user`
--

CREATE TABLE `user` (
  `user_id` int(11) NOT NULL,
  `user_name` varchar(255) NOT NULL,
  `user_email` varchar(50) NOT NULL,
  `user_phone` int(20) NOT NULL,
  `user_password` text NOT NULL,
  `activation_code` int(11) DEFAULT NULL,
  `status` int(11) NOT NULL,
  `created_date` datetime NOT NULL,
  `updated_date` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `user`
--

INSERT INTO `user` (`user_id`, `user_name`, `user_email`, `user_phone`, `user_password`, `activation_code`, `status`, `created_date`, `updated_date`) VALUES
(1, 'sabrina', 'sabrina@gmail.com', 181384848, 'fcea920f7412b5da7be0cf42b8c93759', NULL, 1, '2021-03-12 00:00:00', '2021-03-18 00:00:00'),
(2, ' Kazi', 'kazi@gmail.com', 1365456547, 'fcea920f7412b5da7be0cf42b8c93759', NULL, 2, '2021-03-21 16:10:30', '2021-03-21 16:10:30'),
(3, '', '', 0, 'd41d8cd98f00b204e9800998ecf8427e', NULL, 2, '2021-03-21 18:55:18', '2021-03-21 18:55:18'),
(4, ' Chondro', 'chondro@outlook.com', 1559086854, 'fcea920f7412b5da7be0cf42b8c93759', NULL, 2, '2021-03-21 19:00:52', '2021-03-21 19:00:52');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `contactus`
--
ALTER TABLE `contactus`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `user`
--
ALTER TABLE `user`
  ADD PRIMARY KEY (`user_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `contactus`
--
ALTER TABLE `contactus`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `user`
--
ALTER TABLE `user`
  MODIFY `user_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
