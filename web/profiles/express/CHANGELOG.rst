Changelog
=========

All notable changes to this project will be documented in this file.

The format is based on `Keep a Changelog`__, and this project adheres to `Semantic Versioning`__.

v4.4.9 (2022-01-19)
------------

Changed
~~~~~~~
- Changes to faculty publications module. [AlanBCole]


v4.4.8 (2021-12-15)
------------

Changed
~~~~~~~
- Fix bug in rave_alerts module to ensure display of alerts is as expected.



v4.4.7(2021-12-09)
------------

Changed
~~~~~~~
- Checking for requests that do not have status codes of 200 - requests that time out are not causing issues - reqquests with other errors do not display the rave alert div at all. - all requests with errors are logged using. [AlanBCole]

- Changing contrib module rave_alerts to avoid network error from alert rss feed to cause website errors. [AlanBCole]

- Updated fonts to default to the Roboto font.


Other
~~~~~
- Added updated module code from drupal.org. [AlanBCole]

- Adding call to watchdog if no ACTIVE token is found. [AlanBCole]

- Adding changelog for v.4.4.7. [Jesus Gabriel Ortiz Tovar]

- Updating ldap contrib module to version 7.x-2.6 for PHP 7.4 compatibility. [Jesus Gabriel Ortiz Tovar]



v4.4.6 (2021-06-07)
------------

Changed
~~~~~~~
- Change express site metrics json endpoint to. [AlanBCole]

- Update wywiwyg test. [cathysnider]

- Fix broken funnel pages test. [cathysnider]

- Remove instantiation and developer role from James Fuller. [cathysnider]


Other
~~~~~
- Adding comment about the use of code from atlas_statistics.module. [AlanBCole]

- Using atlas_stistics code that was left out of metrics gathering before. [AlanBCole]

- Changing message in "Please Run Tests" workflow. [Alan Cole]

- Removing sauce labs code. [Alan Cole]

- Adding new workflow to comment run tests in a pr targeting dev. [AlanBCole]

- Including action trigger for adding a label. [AlanBCole]

- Adding token so pr comment can be made. [AlanBCole]

- Trying to check if the pr has been labeled with 'ReadyForTesting' before running the tests, since they take so long. [AlanBCole]

- Tagging failing test as broken. To be looked at in a new issue. [AlanBCole]

- Changing behat.local.yml to match new testing configuration. [AlanBCole]

- Removing a few things that I left in by accident, again. [AlanBCole]

- Removing a few things that I left in by accident. [AlanBCole]

- Created workflow to run our Behat tests. [AlanBCole]

  Tests will be run when a new pr targets dev


v4.4.5 (2021-04-26)
------------

Added
~~~~~
- Getting started with basic use ofJson Web Tokens. [AlanBCole]


Changed
~~~~~~~
- Adjust function to load only one node. [cathysnider]

- Duplicate newsletter archive page function. [cathysnider]

- Add url item for current issue of newsletter. [cathysnider]

- Adding new design for horizontal tabs. Resolves #800. [kevincrafts]


Other
~~~~~
- Simply adding to the variable table in the hook_install() method. No longer using the settings.php file for this, only the express_site_metrics_secret. [AlanBCole]

- Resolving some requested changes: [AlanBCole]

  - fix link paths to include the new url/path
  - Use firebase/php-jwt code directly by simply copy/pasting the JWT class file.
  - Removed hook_cron() implementations from atlas_statistics module, since we are no longer using that to gather metrics data
  - Put JWT class in its own file
  - Some other minor css styling issues
- Resolving most PR comments and issues. Also commenting out hook_cron functions in atlas_statistics. [AlanBCole]

- Added atlas_statistics, cu_atlas, and atlas as dependencies. [AlanBCole]

  Added these because I am using the hook_atlas_statistics() method outlined in atlas_statistics module
- First working version. [AlanBCole]

  Not all metrics data present in atlas statistics is showing up but SOME data is showing up.
- First working version of web token handler. [AlanBCole]

- Started to set up simple unit tests. [AlanBCole]


v4.4.3 (2021-02-03)
-------------------

Changed
~~~~~~~
- Update permissions so that anonymoususers can see JS includes. Resolves #787. [James Fuller]


Other
~~~~~
- Using a more nuanced approach: - filter/tips endpoint should be visible to all users with the 'authenticated user' role - unauthenticated users will be shown the log in page (this is default behavior. I did not implement it) [AlanBCole]

- Making sure function naming is as intended. [AlanBCole]

- Fix: added  method to cu_core. Resolves #790. [AlanBCole]



v4.4.2 (2021-01-13)
------------

Fixed
~~~~~~~

- Update secure perms for JS Includes. [cathysnider]

- Adding border to search block so field is visible. Resolves #740. [kevincrafts]

- Fixing issue where hero units set to image sizing would have extra space at the bottom. Resolves #734. [kevincrafts]

- Hiding search thumbnails. Resolves #771. [kevincrafts]

-  Changed selector used in people_content_type.scss for person photos from  to  in order to make it more specific to the intended situation.

- Add error checking for Layout Title length. [cathysnider]


v4.4.1 (2020-12-07)
------------

Added
~~~~~
- Added a page to list all of a person's publications.
  - if there are any publications authored by the person there will be a list of 5 of them by default
  - if the person has more than 5 publications there will be a link at the bottom of the publications list
  - clicking on the link should take you to a page with a paged list of all the person's publications, most recent first by default.
  - the person's name should be a link to take you back to their Person page
  - Can be configured by visiting /admin/structure/block/manage/cu_faculty_publications_bundle/person_publications_list/configure
  - Can be inserted via Context
  - grabs email from node of the person page it is loaded on.


Deprecated
~~~~~~~
- Removing UI for adding LiveChat widgets. Resolves #744.

- Removing bundle roles from livechat bundle so it can't be enabled.


Fixed
~~~~~
- Allow warning/error messages to float to left side of image without its div overlapping with image's div.

- Fix PATH assignment for drush.


v4.4.0 (2020-10-26)
------------

Added
~~~~~
- Added integration to experts.colorado.edu. Resolves #41.

- New method for including specific types of JavaScript embeds. Resolves #691.

- Added context_error to allow the placement of a search box on a 403 or 404 page. Resolves #123.


Changed
~~~~~~~
- Adding video filter for Wowza livestreaming video service. Resolves #289.


Fixed
~~~~~~~
- Fixing issue where there was an empty role available. Resolves #718.


v4.3.5 (2020-10-14)
------------

Fixed
~~~~~~~
- Replacing incorrect function call. Resolves #736


v4.3.4 (2020-10-12)
------------

Changed
~~~~~~~
- People content type utilizes nested taxonomy terms for filters


Fixed
~~~~~~~
- Fix for counter.js used in the countup shortcode. Resolves #637.

- Fixing links to include full urls, fixing gradient css for article title. Resolves #729.


v4.3.3 (2020-09-29)
------------

Changed
~~~~~~~
- Remove hard-coded Google Analytics ID from Express code base, we will add it during deployment.

- Adding field for multiselect option #599.


Fixed
~~~~~~~
- Degrading gracefully if the collection type term used in the collection block has been deleted. Resolves #685.


v4.3.2 (2020-09-17)
------------

Fixed
~~~~~~~
- Revert Google Tag Manager contrib update. Resolves #707.


v4.3.1 (2020-09-10)
------------

Changed
~~~~~~~
- Replace poor language choices 'master/slave'; 'whitelist/blacklist'.

- Checking to see if alerts xml is valid. Resolves #677.

- Adding back in settings option for sidebars. resolves #517.

- Updated contributed modules

- We now test using our modified Drupal core


Deprecated
~~~~~~~
- All themes are responsive. Fixed width sites have been deprecated. Removed toggle for responsive settings.


Fixed
~~~~~~~
- Fixing notice if a block did not have a bid value. Resolves #696.

- Article slider links are now the correct color. Removed extra/empty links. Resolves #548.


v4.3.0 (2020-04-21)
------------

Added
~~~~~~~
- Adding a setting to hide the subnavigation on mobile devices. Resolves #344.

- Add masquerade module.


Changed
~~~~~~~
- Removing hard coded array of feature names to ignore when overridden. If a feature is expected to be overridden 'settings[can_be_overridden] = 1' should be added to its .info file.

- cu_googleanalytics 'can_be_overridden'.

- cu_home_page 'can_be_overridden'.

- cu_linkchecker 'can_be_overridden'.

- Fixing issue where the excluded blocks in block wrapper weren't set correctly in the last update. Resolves #564.

- Adjusted user_external_invite_user_role_delete() to search for correct variable and remove content_editor rid.

- Allow multiple bylines in articles. resolves #554.

- Update Drupal core version.


Fixed
~~~~~
- Previous and next icons in datepicker no display correctly.

- Horizontal scroll bar no longer displays with the responsive table shortcode on browsers running on Windows. Resolves #530.

- Fix: Article redirects were ignoring query parameters attached to a url. resolves #496.


Removed
~~~~~~~
- Removing deprecated content editor role.

- Removed unused function with its broken link. Resolves #581.


v4.2.2 (2020-05-14)
------------

Added
~~~~~
- Adding large search box block.


Changed
~~~~~~~
- Improving active states for secondary navigation.

- Improve module uninstall process to remove associated roles as well.


Fixed
~~~~~~~
- Fixing issue where some block titles weren't styled correctly.


Removed
~~~~~~~
- Removing deprecated content editor role.


v4.2.1 (2020-04-21)
------------

This release reverts a PR with a bug in it and resolves an increase in logging.

Fixed
~~~~~~~
- New notice in cu_shortcodes module

- External Article Links not working properly


v4.2.0 (2020-04-15)
------------

This release adds site affiliation and improves our visibility into the service.

Added
~~~~~~~
- Setting and enabling site affiliation. Resolves #422.

- Added code to cu_core.install to check for overridden features so that they are displayed as warnings in the /admin/reports/status page.

- Adding fac staff calendar filter to available filters.

- Add Alan Cole and Brooke Stevens to CU Users.

- Add status check for secure perms and mixed authentication mode.


Changed
~~~~~~~
- Pin browser version for automated testing.

- Combine scenarios to increase test speed.

- Can now add a link to an anchor on the same page using the pattern #<anchor_name>

Fixed
~~~~~~~
- Allow users with form_submitter role to be edited and/or deleted. Resolves #244.

- Fixing issue where external article link did not keep url query parameters when redirecting. Resolves #496.

- Fixing issue where hero style images placed in the wysiwyg field would extend outside the edges of the page on the Shadow theme when responsiveness was disabled. Resolves #490.

- Fixing issue where urls with query parameters would not work with rss feeds. Resolves #476.

Deprecated
~~~~~~~
- Disable and uninstall old tracking pixel modules. Resolves #462.


v4.1.4 (2020-02-12)
------------

This release add content types to the default sitemap and removes configuration that had no impact.

Changed
~~~~~~~
- Adding photo galleries, collection items, and section pages to xml site map. #351

- Removing configuration for Block Icon Color. #434


v4.1.3 (2020-01-14)
------------

This release resolves some display bugs.

Added
~~~~~
- Adding Pantheon Advanced Page Cache and d8cache modules.

Changed
~~~~~~~
- Adding test for mega menu rendering. #450

- Fixing issue where block designer theme previews did not show background colors. #445

- Updated Webform from 4.20 to 4.21. #426

- Replacing & with and in affiliation names. #235

Fixed
~~~~~~

- Fixed issue where edit_my_content users could not edit person node they owned. #467

Removed
~~~~~

- Remove testing on PHP 7.1. #460

- Remove admin permission for a user; stop adding them to new sites.

- Removing original read more link on some article view modes. #431

- Remove logging messages during normal RAVE state. #425

v4.1.2 (2019-12-10)
------------

This release adds the 'Save and Add Another' feature to many content types, updated contrib modules, and resolved some CSS bugs.

Added
~~~~~~~

- 'Save and Add Another' functionality added to select content types. #115

Changed
~~~~~~~
- Remove Site Status Section from admin/settings.

- Rebuild secure permissions after removing perms for express site status.

- Adding comments about site affiliation fields, display. #413

- Fixing issue where campus logo would not display at the correct aspect ration in some clients. #393

- Fixed issue where buttons in vertical tabs did not have correct color. #401

- Update webform from 7.x-4.19 to 7.x-4.20. #374

- Updated file_entity from 7.x-2.25 to 7.x-2.27. #374

- Updated google_tag from 7.x-1.4 to 7.x-1.6. #374

- Update link from 7.x-1.6 to 7.x-1.7. #374

- Update captcha from 7.x-1.5 to 7.x-1.6. #374

- Update inline_entity_form from 7.x-1.8 to 7.x-1.9. #374

- Updated unpublished_404 from 7.x-1.1 to 7.x-1.2. #374

- Update field_collection from 7.x-1.0-beta13 to 7.x-1.1. #374

- Update and patch simplesamlphp_auth module.

- Updating variable sets for simplesamlphp_auth_user_name and simplesamlphp_auth_unique_id.

- Updating gemfiles #326

- Sorting social link type options alphabetically #357

- Updated text for bundle request email. #375

- Replacing '&' with 'and' in affiliation names. #235

Fixed
~~~~~
- Changelog is generated correctly.

- Fixing issue where administrators couldn't edit user roles #114.

- Fixing flexbox display of issue grids #326.

Removed
~~~~~~~
- Remove express help module. #361

- Removing zengrids from publication bundle #326

v4.1.1 (2019-11-12)
------------

This update resolves several visual regressions and begins removing unused or broken code.

Added
~~~~~
- Add a Github Action to create a Changelog artifact release branches are opened. #333

Changed
~~~~~
- Fixing issue where image styles were not getting flushed properly #328.

- Setting a dependency for cu_help module #324.

- Update README to better reflect reality of the profile.

- Updating Helpscout beacon to version 2.0 #263.

- Updating newsletter design with new website standards #207.

- Update PHP 7.1 patch version and add PHP 7.2.


Fixed
~~~~~
- Fixing issue where share on twitter link was not creating a tweet #306.

- Adding a background color class for slider style 4 to set link colors correctly #334.

- Fixing issue where social links reference would error if social links were not enabled #343.

- Fixing issue where social links have underlines if nested in multiple background color classes #314.

- Fixing issue where hero image styles where not positioned properly when page layout was set to feature layout #312.

- Fixing notice of missing variable for intro region #325.

Deprecated
~~~~~

- Disabling and uninstall express_help module #324.

Removed
~~~~~

- Remove developer role from devs who are gone.

- Removing redis dependency from pantheon_hosting.info.

- Remove blocked users from the Atlas statistics user report. #195

- Remove debug module Stage File Proxy.

v4.1.0 (2019-10-08)
-------------------

This update adds support for Pardot (Salesforce lead generation) forms, brings the Slate bundle into the core profile, and resolves several CSS bugs.

Added
~~~~~
- Add Pardot embed template module #300.

- Adding slate bundle #62.

Changed
~~~~~
- Removing message about unsetting progress bar in webform node creation #269.

- Move and improve AB tests.

- Update login and user modules to work with SAML.

- Remove features that duplicate tests.

Fixed
~~~~~
- Buttons in slider content gets the wrong text color #258.

- Teaser image display at the wrong aspect ratio if a link wasn't added #305.

- Button text color in card style content grids are the wrong color #292.

Removed
~~~~~
- Remove drupal-org make files.

- Remove developer modules.

v4.0.1 (2019-09-19)
------

Added
~~~~~
- Add developers Jeremy Sparks, Michael Bolei, Christina Morris.

- Added digital campaign and A/B test bundles.

Changed
~~~~~
- Adding cu_saml module to pantheon_hosting dependencies list.

- Updating dependencies and module_disable() in pantheon_hosting module.

- Update module wysiwyg to 7x-2.6.

- Update HTML Title to 7.x-1.5.

Fixed
~~~~~
- Fixing issue where form fields on dark backgrounds might be unreadable #267.

- Fixing issue where article read more link wasn't rendering correctly when part of an issue #227.

- Fix broken test that tested EditOnly access to Block Row blocks.

- Making sure content grid link colors are correct #232.

- Preventing links with fixed colors from inheriting underlines, reducing transparency to help accessibility #232.

- Fixing a spacing issue on teaser display where linked images would add additional padding #232.

- Fixing issue where content grid links would be wrong colors if placed in block sections #232.

- Explicitly telling .travis.yml to initialize mysql.

- Fixing block designer background classes #239.

- Fixing color nesting issues #239.

- Fixing issue where block designer blocks did not the the correct link colors #239.

- Fixing issue where semitransparent content background was fully opaque #234.

- Fixed link to project URL for live chat.

v4.0.0 (2019-08-07)
-----------------

This update begins the process of adding what were separate code bundles back into the core profile, adds the mega menu bundle, and includes various bug fixes and improvements.

Added
~~~~~
- Add mega menu bundle. #48

- Add custom logo to sticky menus. #3

- Add ability to choose brand bar color. #2

Changed
~~~~~
- Consolidate code into a single repository: Campus News, Class Notes, Livestream, Content Sequence, Newsletter, Livechat, Publications, Chemistry Titles, Custom Logo, Responsive Visibility, Section Page, Collections, Video Hero Unit, Localist.

- Make changes to support cloud hosting.

- Increased Form bundle test coverage.

- Setting GTM ID, enabling google_tag on existing sites. #142

Deprecated
~~~~~
- Add instructions and deprecated label to old fields. #3

Removed
~~~~~
- Remove Atlas code UI. #113

- Remove developers from install profile. #221

Fixed
~~~~~
- Logo did not size properly in Firefox. #212

- Test content images did not load. #163

- Correct color of affiliation text/link on black site name banners. #188

- Correct content sequence formating with italics. #214

- Hide text description that is no supposed to appear. #118

- Center 'more' link on campus news grid. #162

- Correct footer link color on simple newsletter theme. #164

- Collection terms sort predictably. #166

- Correct expandable link colors on dark backgrounds. #10

- Correct alignment of hero content at various browser widths. #149

- Improve contrast of block designer outline on dark backgrounds. #158

- User 1 cannot access bundle configuration screens. #145

- Related article calculation is incorrect. #1

- Drupal blocks could not be configured. #121

- Correct section page content on mobile displays. #150

- Some themes have too much padding at wide widths. #151

- Page title had too much horizontal padding on mobile displays. #152

- Correct blocks display with offset icons. #106

- Correct height of lighttheme page titles. #157

- Improve nesting of background color classes. #6

- Fixing notice if a homepage is set to a path that is not a node. #86

- Correct 'site name' line height on non-front pages. #9

- Correct form fields display on dark backgrounds. #8

- Display breadcrumbs when a feature image was set. #7

- Allow teaser content grid to display short text content. #4

- Correct link color when the background color for the region is not correct. #5

Security
~~~~~
- Update Drupal contributed modules. #116


__ https://keepachangelog.com/en/1.0.0/
__ https://semver.org/spec/v2.0.0.html
