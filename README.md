# XMPPNotifier

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
facebook_message("username", "password", "fbid", "R XMPPNotifier testing message")
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