@webform
Feature: Webform initialization
When the Webform bundle is installed
Certain webform functionality is instantiated throughout site

# 1. Form Manager permissions are added to admin/people/invite
# 2. The webform tab appears in admin/content; is properly populated
# 3. Feedback form settings are added to Site Settings page

#1: PERMISSIONS

#2: WEBFORM TAB
Scenario: Functionality - The Webform tab appears in admin/content
Given I am logged in as a user with the "site_owner" role
And I am on "admin/content"
Then I should see the link "Webforms"
And I go to "admin/content/webform"
Then I should see "This page lists all of the content on the site that may have a webform attached to it."
And I should see the link "Add Webform"

#3: FEEDBACK FORM SETTINGS
Scenario: Functionality - Feedback form settings are added to Site Settings
Given I am logged in as a user with the "site_owner" role
And I am on "admin/settings"
Then I should see the link "Feedback Form"
And I go to "admin/settings/forms/feedback"
Then I should see "There are no published webforms available"
