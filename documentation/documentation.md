
<!-- vim-markdown-toc GFM -->

* [Google Chrome](#google-chrome)
	* [Customizing Sight](#customizing-sight)
* [Mozilla Firefox](#mozilla-firefox)
* [Offline](#offline)
	* [Install Markdown Viewer](#install-markdown-viewer)
		* [Linux](#linux)
		* [Windows (?)](#windows-)
* [Mobile](#mobile)
* [Github](#github)

<!-- vim-markdown-toc -->

----

# Google Chrome
If you are on Google Chrome, follow these steps.

* Install the [sight extension](https://chrome.google.com/webstore/detail/sight/epmaefhielclhlnmjofcdapbeepkmggh)
* Go to `chrome://extensions` and select the newly added extension's `Details`.
* Enable the `allow access to file URLs`.
* Click on `allow in incognito mode` if you are using a guest session.
* Restart Chrome if needed.

## Customizing Sight
* Click on the **Sight** icon from the toolbar, and select `options`.
* Choose your theme (I'd suggest you try out `Darkula`).
* Select your preferred font. 
* Select the font size (`Medium` should work fine I guess).
* Choose whether you want to enable `line numberings`.

----

# Mozilla Firefox
To be updated!

----

# Offline
If you don't have a good internet connnectivity or if you'd like to retain a local copy of the repository, follow these steps.

## Install Markdown Viewer
* Install the [markdown extension](https://chrome.google.com/webstore/detail/markdown-viewer/ckkdlimhmcjmikdlpkmbgfkaikojcbjk) to view these files in your browser.
* Go to `chrome://extensions` and select the newly added extension's **Details**.
* Enable the `allow access to file URLs`.
* Click on `allow in incognito mode` if you are using a guest session.
* Restart Chrome if needed.
* You can customize it to hide **TOC** (as I already include one).

### Linux
Open up a terminal and type

```bash
git clone https://github.com/Just-A-Visitor/sugar-rush.git
cd sugar-rush
google-chrome README.md
```

This should open the homepage of the repository in your browser. You can navigate easily now (provided you've added **Sight** and **Markdown Viewer**).

To update your local copy of the repo, open a terminal and type

```bash
cd sugar-rush
git pull
```

### Windows (?)
If you are viewing this on the website, click on download `.zip` file. Extract it to your desired directory. Finally, open the `README.md` file with Google Chrome. Now, you can navigate easily, assuming you have already added **Sight** and **Markdown Viewer**.

If you aren't familiar with Git, you'll have to manually update your clone each time.

----

# Mobile
If you are on mobile, you can view the contents without any issue. However, you wont' be able to read the codes. To enable that feature, you'd have to browse the repository in **Github** (which you can easily do so by clicking `View Project on Github`).

----

# Github
If you don't like the above methods, you can always browse through the repository in Github.
