@express_collections_bundle
Feature: Collection Node
When I login to a Web Express website
As an authenticated user with the right permission
I should be able to create a content sequence block

Scenario Outline: An authenticated user should be able to access the form for adding a collection
  Given  I am logged in as a user with the <role> role
  When I go to "node/add/collection-item"
  Then I should see <message>

  Examples:
  | role            | message                  |
  | edit_my_content | "Access Denied"          |
  | edit_only       | "Access Denied"          |
  | site_owner      | "Create Collection Item" |
  | administrator   | "Create Collection Item" |
  | developer       | "Create Collection Item" |

Scenario: An anonymous user should not be able to access the form for adding a collection
  When I am on "node/add/collection-item"
  Then I should see "Access denied"
