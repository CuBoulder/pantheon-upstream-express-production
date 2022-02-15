@express_localist_bundle
Feature: Campus Events Block
When I login to a Web Express website
As an authenticated user with the right permission
I should be able to create a campus events block

Scenario Outline: An authenticated user should be able to access the form for adding a campus events block
  Given  I am logged in as a user with the <role> role
  When I go to "block/add/localist-events"
  Then I should see <message>

  Examples:
  | role            | message                        |
  | edit_my_content | "Access Denied"                |
  | edit_only       | "Access Denied"                |
  | site_editor     | "Create Localist Events block" |
  | site_owner      | "Create Localist Events block" |
  | administrator   | "Create Localist Events block" |
  | developer       | "Create Localist Events block" |

Scenario: An anonymous user should not be able to access the form for adding a campus news block
  When I am on "block/add/localist-events"
  Then I should see "Access denied"
