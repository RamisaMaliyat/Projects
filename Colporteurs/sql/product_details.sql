-- phpMyAdmin SQL Dump
-- version 5.0.4
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Apr 02, 2021 at 09:47 PM
-- Server version: 10.4.17-MariaDB
-- PHP Version: 7.3.27

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `product_details`
--

-- --------------------------------------------------------

--
-- Table structure for table `book`
--

CREATE TABLE `book` (
  `id` int(11) NOT NULL,
  `pname` varchar(255) DEFAULT NULL,
  `image` varchar(255) DEFAULT NULL,
  `price` double DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `book`
--

INSERT INTO `book` (`id`, `pname`, `image`, `price`) VALUES
(11, 'Novel', 'images/book3.jpg', 338),
(12, 'medical books for MBBS students', 'images/medical.jpg', 1750),
(13, 'Novel', 'images/book8.jpg', 150),
(14, 'The literal meaning of the Holy Quran ', 'images/quran.jpg', 900),
(15, 'Philosophy', 'images/book6.jpg', 250),
(16, 'Nursing Admission guide', 'images/nursing.jpg', 600),
(17, 'Computer Programing', 'images/book10.jpg', 328),
(18, 'government job preparation', 'images/govjob.jpg', 650),
(19, 'Islamic Book', 'images/book5.jpg', 328);

-- --------------------------------------------------------

--
-- Table structure for table `booked`
--

CREATE TABLE `booked` (
  `id` int(11) NOT NULL,
  `pname` varchar(255) DEFAULT NULL,
  `images` varchar(255) DEFAULT NULL,
  `price` double DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `booked`
--

INSERT INTO `booked` (`id`, `pname`, `images`, `price`) VALUES
(1, 'novel', 'images/booka1.jpg', 300),
(2, 'Classical poetry', 'images/book2.jpg', 229),
(3, 'novel', 'images/book3.jpg', 338),
(4, 'Islamic Book', 'images/book4.jpg', 200),
(5, 'Islamic Book', 'images/book5.jpg', 225),
(6, 'Philosophy', 'images/book6.jpg', 328),
(7, 'Tradition', 'images/book7.jpg', 150),
(8, 'Novel', 'images/book8.jpg', 150),
(9, 'Novel', 'images/book9.jpg', 200),
(10, 'Computer Programing', 'images/book10.jpg', 250),
(11, 'Computer Programing', 'images/book11.png', 250),
(12, 'Computer Programing', 'images/book13.jpg', 325),
(13, 'BCS All Subject Book', 'images/bcs.jpg', 1500),
(14, 'Ielts book', 'images/ILTS.jpg', 350),
(15, 'Government job preparation', 'images/govjob.jpg', 650),
(16, 'medical books for MBBS students', 'images/medical.jpg', 1750),
(17, 'Nursing Admission guide', 'images/nursing.jpg', 600),
(18, 'Sat Preparation', 'images/sat.jpg', 250),
(19, 'The literal meaning of the Holy Quran', 'images/quran.jpg', 900),
(20, 'Spoken English', 'images/spoken.jpg', 229),
(21, 'Science fiction', 'images/book13.jpg', 325);

-- --------------------------------------------------------

--
-- Table structure for table `chat`
--

CREATE TABLE `chat` (
  `id` int(11) NOT NULL,
  `user` varchar(255) NOT NULL,
  `message` text NOT NULL,
  `date` timestamp NOT NULL DEFAULT current_timestamp() ON UPDATE current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `login`
--

CREATE TABLE `login` (
  `id` int(11) NOT NULL,
  `firstname` varchar(150) NOT NULL,
  `lastname` varchar(150) NOT NULL,
  `email` varchar(150) NOT NULL,
  `phonenumber` varchar(100) NOT NULL,
  `password` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `magazine`
--

CREATE TABLE `magazine` (
  `id` int(11) NOT NULL,
  `pname` varchar(255) DEFAULT NULL,
  `images` varchar(255) DEFAULT NULL,
  `price` double DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `magazine`
--

INSERT INTO `magazine` (`id`, `pname`, `images`, `price`) VALUES
(1, 'travel', 'images/Ma7.jpg', 20),
(2, 'technology', 'images/Ma3.jpg', 25),
(3, 'bussiness', 'images/Ma9.png', 30);

-- --------------------------------------------------------

--
-- Table structure for table `magazined`
--

CREATE TABLE `magazined` (
  `id` int(11) NOT NULL,
  `pname` varchar(255) DEFAULT NULL,
  `images` varchar(255) DEFAULT NULL,
  `price` double DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `magazined`
--

INSERT INTO `magazined` (`id`, `pname`, `images`, `price`) VALUES
(1, 'travel', 'images/Ma1.png', 20),
(2, 'technology', 'images/Ma2.jpg', 25),
(3, 'technology', 'images/Ma3.jpg', 25),
(4, 'technology', 'images/Ma4.jpg', 27),
(5, 'Study', 'images/Ma5.jpg', 30),
(6, 'comics', 'images/Ma6.jpg', 16),
(7, 'travel', 'images/Ma7.jpg', 22),
(8, 'travel', 'images/Ma8.jpg', 25),
(9, 'bussiness', 'images/Ma9.png', 30);

-- --------------------------------------------------------

--
-- Table structure for table `private`
--

CREATE TABLE `private` (
  `id` int(11) NOT NULL,
  `username` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `private`
--

INSERT INTO `private` (`id`, `username`, `email`, `password`) VALUES
(25, 'ramisa', 'sultanarebeka@gmail.com', '827ccb0eea8a706c4c34a16891f84e7b'),
(26, 'ramisa', 'admin@admin.com', '900150983cd24fb0d6963f7d28e17f72');

-- --------------------------------------------------------

--
-- Table structure for table `product`
--

CREATE TABLE `product` (
  `id` int(11) NOT NULL,
  `pname` varchar(255) DEFAULT NULL,
  `image` varchar(255) DEFAULT NULL,
  `price` double DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `product`
--

INSERT INTO `product` (`id`, `pname`, `image`, `price`) VALUES
(1, 'laptop', 'images/laptoppic.jpg', 56000),
(2, 'Highlighter Pen', 'images/marker.jpg', 100),
(3, 'HeadPhones', 'images/headph.jpg', 200),
(4, 'Note Books', 'images/note.jpg', 25),
(5, 'Charger', 'images/charger.jpg', 90),
(6, 'School bag', 'images/bag.jpg', 100);

-- --------------------------------------------------------

--
-- Table structure for table `student_info`
--

CREATE TABLE `student_info` (
  `Name` varchar(300) NOT NULL,
  `ID` varchar(255) NOT NULL,
  `Email` varchar(300) NOT NULL,
  `Contact` varchar(300) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `student_info`
--

INSERT INTO `student_info` (`Name`, `ID`, `Email`, `Contact`) VALUES
('Ramisa Maliyat', '18.01.04.079', '180104079@aust.edu', '01716234579'),
('Sadia Sultana', '18.01.04.094', '180104094@aust.edu', '01559086854');

-- --------------------------------------------------------

--
-- Table structure for table `study`
--

CREATE TABLE `study` (
  `id` int(11) NOT NULL,
  `pname` varchar(255) DEFAULT NULL,
  `images` varchar(255) DEFAULT NULL,
  `price` double DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `study`
--

INSERT INTO `study` (`id`, `pname`, `images`, `price`) VALUES
(1, 'laptop', 'images/laptoppic.jpg', 56000),
(2, 'HeadPhones', 'images/headph.jpg', 25),
(3, 'Charger', 'images/charger.jpg', 50),
(4, 'Table Lamp', 'images/lamp.jpg', 90),
(5, 'iphone', 'images/phone.jpg', 10000),
(6, 'Laptop bag', 'images/lbag.jpg', 70),
(7, 'Note Books', 'images/note.jpg', 25),
(8, 'School bag', 'images/bag.jpg', 90),
(9, 'Highlighter Pen', 'images/marker.jpg', 10),
(10, 'Water bottole', 'images/bottle.jpg', 30),
(11, 'Pencil Box', 'images/box.jpg', 20),
(12, 'Document Holder', 'images/document.jpg', 25),
(13, 'Glitter Pen', 'images/glitter.jpg', 15),
(14, 'penholder', 'images/penholder.jpg', 20),
(15, 'sessiors', 'images/sessior.jpg', 10);

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
  `id` int(11) NOT NULL,
  `username` varchar(255) DEFAULT NULL,
  `password` varchar(255) DEFAULT NULL,
  `email` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `book`
--
ALTER TABLE `book`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `booked`
--
ALTER TABLE `booked`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `chat`
--
ALTER TABLE `chat`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `login`
--
ALTER TABLE `login`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `magazine`
--
ALTER TABLE `magazine`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `magazined`
--
ALTER TABLE `magazined`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `private`
--
ALTER TABLE `private`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `product`
--
ALTER TABLE `product`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `study`
--
ALTER TABLE `study`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `book`
--
ALTER TABLE `book`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=20;

--
-- AUTO_INCREMENT for table `booked`
--
ALTER TABLE `booked`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=22;

--
-- AUTO_INCREMENT for table `chat`
--
ALTER TABLE `chat`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=25;

--
-- AUTO_INCREMENT for table `login`
--
ALTER TABLE `login`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=16;

--
-- AUTO_INCREMENT for table `magazine`
--
ALTER TABLE `magazine`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT for table `magazined`
--
ALTER TABLE `magazined`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- AUTO_INCREMENT for table `private`
--
ALTER TABLE `private`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=27;

--
-- AUTO_INCREMENT for table `product`
--
ALTER TABLE `product`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- AUTO_INCREMENT for table `study`
--
ALTER TABLE `study`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=16;

--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
