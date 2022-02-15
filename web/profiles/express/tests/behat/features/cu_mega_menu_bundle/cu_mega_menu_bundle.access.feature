@cu_mega_menu_bundle
Feature: Mega Menu
When I login to a Web Express website
As an authenticated user with the right permission
I should be able to create a mega menu

Scenario Outline: An authenticated user should be able to access the form for adding a mega menu
  Given  I am logged in as a user with the <role> role
  When I go to "admin/structure/mega-menu/add"
  Then I should see <message>

  Examples:
    | role            | message                        |
    | edit_my_content | "Access Denied"                |
    | edit_only       | "Access Denied"                |
    | site_editor     | "Add a Mega Menu" |
    | site_owner      | "Add a Mega Menu" |
    | administrator   | "Add a Mega Menu" |
    | developer       | "Add a Mega Menu" |

Scenario: An anonymous user should not be able to access the form for adding a mega menu
  When I am on "admin/structure/mega-menu/add"
  Then I should see "Access denied"
