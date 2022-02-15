@settings @core
Feature: Site Name identifies the Web Express website; appears in top banner
In order to identify what Web Express site this is
An authenticated user with the proper role
Should be able to set the website name

Scenario Outline: Devs, Admins, SOs and ConMgrs can access Site Name
Given I am logged in as a user with the <role> role
When I go to "admin/settings/site-configuration/site-name"
Then I should see <message>

Examples:
| role             | message |
| developer        | "Site Name" |
| administrator    | "Site Name" |
| site_owner       | "Site Name" |
| edit_my_content  | "Access denied" |
| site_editor      | "Access denied" |
| edit_only        | "Access denied" |
| access_manager   | "Access denied" |
| configuration_manager | "Site Name" |


Scenario: An anonymous user should not be able to set site name
 When I am on "admin/settings/site-configuration/site-name"
 Then I should see "Access denied"

Scenario: Changing the Site Name
Given I am logged in as a user with the "site_owner" role
When I go to "admin/settings/site-configuration/site-name"
And I fill in "edit-site-name" with "My Web Express Site"
And I press "Save configuration"
Then I should see "The configuration options have been saved."
When I go to "/"
Then I should see "My Web Express Site"
