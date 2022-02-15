@newsArticles
Feature: News and Articles
In order to display aggregations of articles
As an authenticated user
I should be able to create, edit, and delete Article List Page content

Scenario Outline: An authenticated user should be able to access the form for adding people list page content
Given I am logged in as a user with the <role> role
When I go to "node/add/article-list-page"
Then I should see <message>

  Examples:
  | role                  | message                   |
  | edit_my_content       | "Access denied"           |
  | site_owner            | "Create Article List Page" |
  | administrator         | "Create Article List Page" |
  | developer             | "Create Article List Page" |
  | configuration_manager | "Access denied"           |
  | site_editor           | "Create Article List Page" |
  | edit_only             | "Access denied"           |
  | access_manager        | "Access denied"           |

Scenario: An anonymous user should not be able to access the form for adding people list page content
When I am on "node/add/article-list-page"
Then I should see "Access denied"

Scenario: A Simple Article List page displays all articles created
Given I am logged in as a user with the "site_owner" role
When I go to "node/add/article-list-page"
And I should see an "#edit-addanother" element
And  I fill in "edit-title" with "News Page"
And the "edit-menu-enabled" checkbox should be checked
When I uncheck "edit-menu-enabled"
And I press "Save"
Then I should see "News Page"
And I should see "An article about Ralphie"
And I should see "Lunch is served at the Center for Community"
And I follow "Edit"
Then the checkbox "edit-menu-enabled" should be unchecked
And I press "Cancel edit"

Scenario: A user with the Edit Only role can edit but not delete Article List Pages
Given I am logged in as a user with the "edit_only" role
And am on "news-page"
And I follow "Edit"
Then I should see "This document is now locked against simultaneous editing."
And I should not see an "edit-delete" element
And I press "Cancel edit"
