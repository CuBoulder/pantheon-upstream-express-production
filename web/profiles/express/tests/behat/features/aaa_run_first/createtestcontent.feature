@TestContent
Feature: Creating Test Content
In order to test Web Express functionality with Behat
As a user with any role at all
Test Content must be created

Scenario: Create Test Nodes
Given I am logged in as a user with the "site_owner" role
# CREATE BASIC PAGE
And I am on "node/add/page"
And fill in "edit-title" with "TestBasicPage"
And I fill in "Body" with "This is a Basic Page"
When I uncheck "edit-menu-enabled"
And I press "Save"
Then I should see "TestBasicPage"
# CREATE ARTICLE
And I go to "node/add/article"
And fill in "edit-title" with "TestArticle"
And fill in "Body" with "Demo article content"
And I press "Save"
Then I should see "TestArticle"
# CREATE PERSON
And I go to "node/add/person"
Then I should see "Create Person"
And fill in "First Name" with "TestFirstName"
And fill in "Last Name" with "TestLastName"
And I press "Save"
Then I should see "TestFirstName TestLastName"
