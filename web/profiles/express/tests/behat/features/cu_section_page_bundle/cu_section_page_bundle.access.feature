@cu_section_page_bundle
Feature: Section Page Node Type
When I login to a Web Express website
As an authenticated user with the right permission
I should be able to create a Section page

Scenario Outline: An authenticated user should be able to access the form for adding a section page
  Given  I am logged in as a user with the <role> role
  When I go to "node/add/section-page"
  Then I should see <message>

  Examples:
  | role            | message               |
  | edit_my_content | "Access Denied"       |
  | edit_only       | "Access Denied"       |
  | site_owner      | "Create Section Page" |
  | administrator   | "Create Section Page" |
  | developer       | "Create Section Page" |

Scenario: An anonymous user should not be able to access the form for adding a section page
  When I am on "node/add/section-page"
  Then I should see "Access denied"

# CHECK THAT SIMPLE NODE CAN BE CREATED
Scenario: Node Functionality - A Section Page can be created; form contains Section Page settings
  Given I am logged in as a user with the "site_owner" role
  And I am on "node/add/section-page"
  Then I should see "Hide Page Title & Breadcrumbs"
  And I should see "Display Section Navigation"
  And I should see "Full Height Sections"
  Then I fill in "edit-title" with "My Section Page"
  And I fill in "Body" with "Lorem ipsum dolor sit amet"
  And I press "edit-submit"
  Then I should see "My Section Page"
