## Upon New D7 Releases
Inside a local copy of the this repository run the following commands:
### Create new local branch
- change `xx` to the issue's number
```
git checkout -b feature/xx
```
### Clone the new Drupal 7 codebase.
- change `7.xx` to what the current version is.
```
$ git clone https://git.drupalcode.org/project/drupal.git --branch 7.xx --single-branch
```
### Copy the new code into the root level of d7core's repo
```
$ cp -rf drupal/* . && \
  cp drupal/.editorconfig . && \
  cp drupal/.gitignore . && \
  cp drupal/.htaccess .
```
### Remove modules we do not require
```
$ rm -rf web.config \
  modules/php \
  modules/aggregator \
  modules/blog \
  modules/book \
  modules/color \
  modules/contact \
  modules/translation \
  modules/dashboard \
  modules/forum \
  modules/locale \
  modules/openid \
  modules/overlay \
  modules/poll \
  modules/rdf \
  modules/search \
  modules/statistics\
   modules/toolbar \
  modules/tracker \
  modules/trigger \
  drupal
```
### Apply patches to codebase for expected functionality
```
$ git apply patches/2789723-1.patch && \
  git apply patches/d7-require-tld-for-mailto-links-2016739-76.patch && \
  git apply patches/watchdog_pending_updates.patch
```
### Commit and push changes up to
```
$ git add *
$ git status
$ git commit -m 'Hardened 7.xx core.'
$ git push -u origin feature/xx
```
