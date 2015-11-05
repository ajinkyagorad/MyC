
set key inside right top vertical Right noreverse noenhanced autotitle nobox
set datafile missing '-'
set style data linespoints
set xtics border in scale 1,0.5 nomirror rotate by -45  autojustify
set xtics  norangelimit
set xtics   ()
set title "US immigration from Europe by decade" 
x = 0.0
i = 22
## Last datafile plotted: "data.csv"
plot 'immigration.csv' using 2:xtic(1) title columnheader(2), for [i=3:22] '' using i title columnheader(i)