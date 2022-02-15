@responsive_visibiity
Feature: Responsive Visibility Block
When I login to a Web Express website
As an authenticated user with the right permission
I should be able to create a Responsive Visibility block

Scenario Outline: An authenticated user should be able to access the form for adding a class note
  Given  I am logged in as a user with the <role> role
  When I go to "block/add/responsive-visibility"
  Then I should see <message>

  Examples:
  | role            | message                  |
  | edit_my_content | "Access Denied"          |
  | edit_only       | "Access Denied"          |
  | site_owner      | "Create Responsive Visibility block" |
  | administrator   | "Create Responsive Visibility block" |
  | developer       | "Create Responsive Visibility block" |

Scenario: An anonymous user should not be able to access the form for adding a class note
  When I am on "block/add/responsive-visibility"
  Then I should see "Access denied"
