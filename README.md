# RMessenger

Do you want R notify yourself after time comsuming simulation? 

Try `RMessenger` which sends message via *Google Talk*, *Facebook* or
other service which follows XMPP protocol.

## Install

For Ubuntu:

```sh
sudo apt-get install libssl-dev libxml2-dev pkg-config
```

Please confirm the version of R( >= 2.15.2 ) and Rcpp( >= 0.10.2 ).

``` r
install.packages("Rcpp")
```

Download the source package from https://dl.dropbox.com/u/11900271/Wush-R-pkg-src/RMessenger_0.1.1.tar.gz and call `R CMD INSTALL` to install

This package is unavailable on Windows

## Google Talk

```r
# not run
# sendXMPPMessage("sender@gmail.com", "sender_passwd", "receiver@gmail.com", "message_content")
```

## Facebook

Send a message to a specific fbid:

```r
library(RMessenger)
# not run
# facebookMessage("wush", "shouldnotbehere", "12345678", "RMessenger testing message test chinese 測試中文")
```

## How to query fbid

- right click on your facebook profile image
- choose `Copy Image URL` link
- Paste the link in a notepad. You should received a link like:  
	```
	http://profile.ak.fbcdn.net/hprofile-ak-snc4/275632_764210555_1265212477_q.jpg
	```
- The number between `_` is the user ID such as `764210555` in the previous example.

## 安裝

Ubuntu請先安裝：

```sh
sudo apt-get install libssl-dev libxml2-dev pkg-config
```

R中請確認版本為2.15.2以上，Rcpp請確認為0.10.2以上。

``` r
install.packages("Rcpp")
```

請下載 https://dl.dropbox.com/u/11900271/Wush-R-pkg-src/RMessenger_0.1.1.tar.gz 後使用`R CMD INSTALL`來安裝

Windows目前無法使用

## Google Talk

```r
# not run
# sendXMPPMessage("sender@gmail.com", "sender_passwd", "receiver@gmail.com", "message_content")
```

## Facebook

發送訊息給特定的fbid

```r
library(RMessenger)
# not run
# facebookMessage("wush", "password_of_wush", "12345678", "RMessenger testing message 中文測試")
```

## 如何查詢fbid

- 右鍵點一個使用者的圖像
- 選擇`複製影像網址`
- 將網址貼出來。可能會看到如下的網址：
	```
	http://profile.ak.fbcdn.net/hprofile-ak-snc4/275632_764210555_1265212477_q.jpg
	```
- 介於`_`的數字就是fbid(例如上面連結中的`764210555`)


# Reference

- [Getting Facebook User ID](http://dragonslayerclan.org/index.php/component/content/article?id=22)
