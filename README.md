# DingDong Application

A simple project taht analyzes social media contest influencer performance data. The app is implemented in C++ and provides an interactive command-line menu for reading influencer statistics, computing per-post metrics, filtering and sorting results, generating performance reports, and searching participants by surname.

## Features

- Read and display contest statistics for 12 finalists from `social_media_contest_data.txt`
- Compute per-post metrics: views/post, engagements/post, likes/post, comments/post, shares/post
- Filter and sort influencers by likes per post
- Calculate a weighted performance metric and sort influencers by that metric
- Allow user-selected sorting by multiple processed fields
- Generate and save processed statistic reports to text files
- Compare average performance between male and female influencers
- Search for participants by surname

## Files

- `DingDongApp.cpp` - main application source code
- `social_media_contest_data.txt` - input data for contest finalists
- `social_media_contest_data.csv` - optional data export/reference file
- `social_media_sorted_stats.txt` - generated output file for sorted statistics (created by the app)
- `social_media_contest_processed_data.txt` - generated output file used for metric sorting

## Requirements

- C++ compiler supporting C++11 or later (for example `g++`)

## Build and Run

From the project directory, compile the program with:

```bash
g++ -std=c++11 "DingDongApp.cpp" -o DingDongApp
```

Then run the executable:

```bash
./DingDongApp
```

## Usage

When the app starts, a menu appears with numbered options:

1. Read and display contest stats for the 12 finalists
2. Calculate and display per post data values
3. Filter and sort data by likes/post
4. Display sorted data based on a novel performance metric
5. Parametrized sorting, display and saving of processed data
6. Compare men's and women's metrics
7. Search participant by surname
0. Exit the program

First use option `1` to load the input file. After the file is read, the other options become available.

## Notes

- The app expects the data file `social_media_contest_data.txt` to be present in the same folder as the executable.
- Report files are created in the working directory when using options 4 and 5.
- Input validation is included for menu selections and numeric entry values.

## License

This project is released under the MIT License.
