"use strict"
 
var fs = require('fs');
 
var input = fs.readFileSync('input.txt', 'UTF-8').split(/\s+/g);


 
var n = parseInt(input[0]);
var m = parseInt(input[1]);
var c = n * m;
var a = new Array(n);
a.forEa
 
var maxDigit = 0;
for (let i = 0; i < n; i++)
    if (digits[i] > maxDigit)
        maxDigit = digits[i];
 
var rowsCount = n * 6 + 1;
var columnCount = maxDigit + 3;
 
function matrixArray(columns, rows){
  var arr = new Array();
  for(let i = 0; i < columns; i++){
    arr[i] = new Array();
    for(let j = 0; j < rows; j++)
        i == 0 ? arr[i][j] = '-' : arr[i][j] = '.';
  }
  return arr;
}
var histogram = matrixArray(columnCount,rowsCount);
 
function drawNumber(num, index){
    for (let i = 0; i <= num + 1; i++){
        for (let j = (index * 6 + 1); j <= (index * 6 + 6); j++){
            if ((j == (index * 6 + 1)) || (j == (index * 6 + 5)))
                ((i > 0) && (i < num + 1)) ? histogram[i][j] = '|' : histogram[i][j] = '+';
            else
                if (j != (index * 6 + 6))
                  ((i > 0) && (i < num + 1)) ? histogram[i][j] = '#' : histogram[i][j] = '-';                 
        }
    }
}
 
for (let i = 0; i < n; i++)
    drawNumber(digits[i], i);
 
var ans = '';
 
for(let i = columnCount - 1; i >= 0; i--){
    for(let j = 0; j < rowsCount; j++)
        ans += histogram[i][j];
    ans += '\n';
 }
 
 console.log(ans);
 
fs.writeFileSync('output.txt', ans);