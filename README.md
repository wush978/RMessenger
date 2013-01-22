# XMPPNotifier

## 安裝

```r
library(devtools)
install_github("XMPPNotifier", username="wush978")
```

也可以下載source後使用`R CMD INSTALL`來安裝

Windows使用者需要安裝Rtools

## Facebook

發送訊息給特定的fbid

```r
library(XMPPNotifier)
# not run
# facebookMessage("wush", "shouldnotbehere", "12345678", "R XMPPNotifier testing message")
```

## 如何查詢fbid

- 右鍵點一個使用者的圖像
- 選擇`複製影像網址`
- 將網址貼出來。可能會看到如下的網址：
	```
	http://profile.ak.fbcdn.net/hprofile-ak-snc4/275632_764210555_1265212477_q.jpg
	```
- 介於`_`的數字就是fbid(例如上面連結中的`764210555`)

## Install

```r
library(devtools)
install_github("XMPPNotifier", username="wush978")
```

or you can download the source and build with `R CMD INSTALL`

Windows User please install `Rtools` first.

## Facebook

Send a message to a specific fbid:

```r
library(XMPPNotifier)
# not run
# facebookMessage("wush", "shouldnotbehere", "12345678", "R XMPPNotifier testing message")
```

## How to query fbid

- right click on your facebook profile image
- choose `Copy Image URL` link
- Paste the link in a notepad. You should received a link like:  
	```
	http://profile.ak.fbcdn.net/hprofile-ak-snc4/275632_764210555_1265212477_q.jpg
	```
- The number between `_` is the user ID such as `764210555` in the previous example.

# Reference

- [Getting Facebook User ID](http://dragonslayerclan.org/index.php/component/content/article?id=22)