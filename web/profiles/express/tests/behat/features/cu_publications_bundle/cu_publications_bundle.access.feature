@cu_publications_bundle
Feature: Issue Node Type
When I login to a Web Express website
As an authenticated user with the right permission
I should be able to create an Issue

Scenario Outline: An authenticated user should be able to access the form for adding an issue
  Given  I am logged in as a user with the <role> role
  When I go to "node/add/issue"
  Then I should see <message>

  Examples:
  | role            | message         |
  | edit_my_content | "Access Denied" |
  | edit_only       | "Access Denied" |
  | site_owner      | "Create Issue"  |
  | administrator   | "Create Issue"  |
  | developer       | "Create Issue"  |

Scenario: An anonymous user should not be able to access the form for adding an issue
  When I am on "node/add/issue"
  Then I should see "Access denied"

# CREATE TEST ARTICLE
Scenario: Create a Article for Testing
  Given I am logged in as a user with the "site_owner" role
  And I go to "node/add/article"
  And fill in "edit-title" with "NewTestArticle"
  And I press "Save"
  Then I should see "NewTestArticle"

# CHECK THAT SIMPLE NODE CAN BE CREATED
Scenario: Node Functionality - A very basic Issue node can be created; Display options are populated
  Given I am logged in as a user with the "site_owner" role
  And I am on "node/add/issue"
  And fill in "edit-title" with "Test Issue"
  And fill in "Body" with "Read All About It"
  And I fill in "edit-field-issue-image-insert-und-0-alt" with "Fantasy Mountains"
  And I attach the file "behatBanner1.jpg" to "edit-field-issue-image-insert-und-0-upload"
  And I press "Upload"
  #  And I wait 5 seconds
  And I fill in "edit-field-issue-section-und-0-field-issue-section-title-und-0-value" with "First Section"
  And I fill in "edit-field-issue-section-und-0-field-issue-section-articles-und-0-target-id" with "NewTestArticle"
  And I select "Teaser" from "edit-field-issue-section-und-0-field-issue-section-display-und"
  And I select "Feature" from "edit-field-issue-section-und-0-field-issue-section-display-und"
  And I select "Title and Thumbnail" from "edit-field-issue-section-und-0-field-issue-section-display-und"
  And I select "Title" from "edit-field-issue-section-und-0-field-issue-section-display-und"
  When I press "edit-submit"
  Then I should see "Test Issue"
  And I should see "Read All About It"
  And I should see "First Section"
  And I should see "NewTestArticle"
