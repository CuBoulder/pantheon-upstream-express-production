@digital_campaign @tracking_pixels
Feature: the Digital Campaign bundle
In order to test the results of a digital campaign
A user with the proper role
Should be able to access, create and edit tracking pixel embeds.

Scenario Outline: Access Embed Templates Overview Page.
  Given I am logged in as a user with the <role> role
  And am on "admin/content/embeds"
  Then I should see <message>

  Examples:
    | role                  | message         |
    | site_owner            | "Add Embeds"    |
    | administrator         | "Add Embeds"    |
    | developer             | "Add Embeds"    |
    | campaign_manager      | "Add Embeds"    |
    | edit_my_content       | "Access Denied" |
   # | authenticated_user    | "Access Denied" |
    | site_editor           | "Access Denied" |
    | edit_only             | "Access Denied" |
    | access_manager        | "Access Denied" |
    | configuration_manager | "Access Denied" |

Scenario: Create a Facebook tracking pixel.
  Given I am logged in as a user with the "site_owner" role
  And I am on "admin/content/embeds/add/facebook"
  And I fill in "Label" with "Facebook Tracking Pixel"
  And I fill in "Path" with "node/1"
  And I fill in "ID" with "123456"
  And I select "Published" from "Status"
  When I press "Save"
  And I go to "node/1"
  Then the response should contain "https://www.facebook.com/tr?id=123456&ev=PageView&noscript=1"

Scenario: Create a DoubleClick tracking pixel.
  Given I am logged in as a user with the "site_owner" role
  And I am on "admin/content/embeds/add/doubleclick"
  And I fill in "Label" with "DoubleClick Tracking Pixel"
  And I fill in "Path" with "node/1"
  And I fill in "ID" with "452315"
  And I fill in "Activity" with "activity_one"
  And I fill in "Creation Date" with "creation_date_one"
  And I fill in "Page Location" with "location_one"
  And I fill in "Type" with "type_one"
  And I fill in "Category" with "category_one"
  And I select "Top" from "Position"
  And I select "Published" from "Status"
  When I press "Save"
  And I go to "node/1"
  Then the response should contain "document.write('<iframe src=\"https://452315.fls.doubleclick.net/activityi;src=452315;type=type_one;cat=category_one;dc_lat=;dc_rdid=;tag_for_child_directed_treatment=;ord=' + a + '?\" width=\"1\" height=\"1\" frameborder=\"0\" style=\"display:none\"></iframe>');"

Scenario: Create a Twitter tracking pixel.
  Given I am logged in as a user with the "site_owner" role
  And I am on "admin/content/embeds/add/twitter"
  And I fill in "Label" with "Twitter Tracking Pixel"
  And I fill in "Path" with "node/1"
  And I fill in "ID" with "456789"
  And I fill in "Activity" with "activity_nine"
  And I select "Published" from "Status"
  When I press "Save"
  And I go to "node/1"
  Then the response should contain "twq('init', '456789');"
  And the response should contain "twq('track', 'PageView');"
  And the response should contain "twq('track', 'activity_nine');"

# Tracking pixels can be searched; only embeds that match the search criteria are returned
Scenario: A user can search the list of embedded tracking pixels
  Given I am logged in as a user with the "site_owner" role
  And I am on "admin/content/embeds"
  Then I should see "search for embed by name"
  And I select "Facebook" from "Embed Type"
  And I press "Search"
  Then I should see "Facebook Tracking Pixel"
  And I should not see "Twitter Tracking Pixel"
  And I should not see "DoubleClick Tracking Pixel"

Scenario: Create a LinkedIn Insight Tag tracking pixel.
  Given I am logged in as a user with the "campaign_manager" role
  And I am on "admin/content/embeds/add/et_linkedin"
  And I fill in "Label" with "LinkedIn Tracking Pixel"
  And I fill in "Path" with "node/1"
  And I fill in "Account ID" with "9030612"
  And I fill in "Position" with "bottom"
  And I select "Published" from "Status"
  When I press "Save"
  And I go to "node/1"
  Then the response should contain "_linkedin_data_partner_id = \"9030612\";"
  And the response should contain "<img height=\"1\" width=\"1\" style=\"display:none;\" alt=\"\" src=\"https://dc.ads.linkedin.com/collect/?pid=9030612&fmt=gif\"/>"
