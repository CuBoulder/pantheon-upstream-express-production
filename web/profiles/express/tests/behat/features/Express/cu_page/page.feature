@page @core
Feature: Basic Page Content Type
When I login to a Web Express website
As a user with the proper role
I should be able to create, edit, and delete Basic Pages

  # NOTE: THERE IS CURRENTLY NO KNOWN WAY TO PRESS THE INSERT BUTTON; GRAPHICS CAN BE UPLOADED BUT NOT INSERTED
  # CONTINUE TESTING THIS PROBLEM WITH PHOTOINSERT.FEATURE

  # 1) CHECK NODE ADD PRIVILEGES
  # 2) CHECK THAT SIMPLE NODE CAN BE CREATED AND REVISED
  # 3) CHECK EDITING AND DELETING PRIVILEGES ON THE CONTENT JUST MADE
  # 4) CHECK THAT DELETE BUTTON ACTUALLY WORKS
  # 5) CHECK MORE COMPLEX NODE CREATION

  # 1) CHECK NODE ADD PRIVILEGES
  Scenario Outline: Node Access - Some roles can add Basic Page content
    Given I am logged in as a user with the <role> role
    When I go to "node/add/page"
    Then I should see <message>

    Examples:
      | role            | message             |
      | developer       | "Create Basic page" |
      | administrator   | "Create Basic page" |
      | site_owner      | "Create Basic page" |
      | edit_my_content | "Access denied"     |
      | site_editor     | "Create Basic page" |
      | edit_only       | "Access denied"     |

  Scenario: Node Access -  An anonymous user cannot add Basic Page content
    When I am on "node/add/page"
    Then I should see "Access denied"

  #  2) CHECK THAT SIMPLE NODE CAN BE CREATED
  Scenario: Node Functionality - A very basic Basic Page node can be created
  Given I am logged in as a user with the "site_owner" role
  And I am on "node/add/page"
  And fill in "edit-title" with "My Page"
  And fill in "Body" with "Lorem ipsum dolor sit amet"
  Then the "edit-menu-enabled" checkbox should be checked
  And I should see an "#edit-addanother" element
  When I press "edit-submit"
  Then I should be on "/my-page"
  And I should see "My Page"
  And I should see "Lorem ipsum dolor sit amet"

  # 2.1) CHANGE AUTHOR OF THE PAGE NODE AND CREATE REVISIONS
  Scenario: Node functionality - Change Authorship of node on node/%/edit; create revision
    Given I am logged in as a user with the "site_owner" role
    And I am on "/my-page"
    And I follow "Edit"
    And I fill in "Authored by" with "edit_my_content"
    When I press "Save"
    And I should see the link "Revisions"
    And I follow "Edit"
    Then the "Authored by" field should contain "edit_my_content"
    And I press "Cancel edit"

    @broken
    #TO DO: CHECK TO SEE IF THIS SCENARIO NEEDS JAVASCRIPT
    Scenario: Node functionality - Change Authorship of node on admin/content
    Given I am logged in as a user with the "site_owner" role
    And I am on "admin/content"
    And I check "edit-views-bulk-operations-0"
    And I select "Change the author of content" from "edit-operation"
    And I press "Execute"
    Then I should see "The username of the user to which you would like to assign ownership."
    And I select "edit_my_content" from "edit-owner-name"
    And I press "Next"
    Then I should see "Are you sure you want to perform Change the author of content on the selected items"
    When I press "edit-submit"
    And I wait 5 seconds
    Then I should be on "admin/content"
    Then I should see "Performed Change the author of content on 1 item"


  # 3) CHECK EDITING AND DELETING PRIVILEGES ON THE CONTENT JUST MADE
  Scenario Outline: Node Access -  Some roles can edit and delete Basic Page content
  Given I am logged in as a user with the <role> role
  And I am on "/my-page"
    Then I should see the link "View"
    And I should see the link "Edit"
    And I should see the link "Edit Layout"
    And I should see the link "Revisions"
    And I should see the link "Clear Page Cache"
    When I follow "Edit"
    Then I should see "This document is now locked against simultaneous editing."
    And I should see an "#edit-delete" element
    And I press "Cancel edit"

    Examples:
      | role           |
      | developer      |
      | administrator  |
      | site_owner     |
      | site_editor    |

  Scenario: Node Access -  EditOnly can edit and revise but not delete node
  Given I am logged in as a user with the "edit_only" role
  And I am on "/my-page"
  Then I should see the link "View"
  And I should see the link "Edit"
  And I should not see the link "Edit Layout"
  And I should see the link "Revisions"
  And I should see the link "Clear Page Cache"
  When I follow "Edit"
  Then I should see "This document is now locked against simultaneous editing."
  And I should not see an "#edit-delete" element
  And I press "Cancel edit"

  # edit_my_content role is assigned on page.feature:53
  Scenario: Node Access -  EditMyContent can edit Basic Pages if owner but cannot delete
  Given I am logged in as a user with the "edit_my_content" role
  And I am on "/my-page"
  Then I should see the link "View"
  And I should see the link "Edit"
  And I should not see the link "Edit Layout"
  And I should not see the link "Clear Page Cache"
  When I follow "Edit"
  Then I should not see an "#edit-delete" element
  When I fill in "Body" with "EditMyContent has changed their content."
  And I press "Save"
  Then I should see "EditMyContent has changed their content."


  # 4) CHECK THAT PAGE CAN BE DELETED
  Scenario: Verify that the Delete button actually works
  Given I am logged in as a user with the "site_owner" role
  And I am on "/my-page"
  And I follow "Edit"
  And I press "Delete"
  Then I should see "Are you sure you want to delete My Page?"
  And I press "Delete"
  Then I should see "Basic page My Page has been deleted."
  And I am on "/"

  # 5) CHECK MORE COMPLEX NODE CREATION; USE FOR TEST PAGES LATER ON
  Scenario: A graphic can be uploaded to a Basic Page node
  Given I am logged in as a user with the "site_owner" role
  And I am on "node/add/page"
  And fill in "edit-title" with "Test Page One"
  And fill in "Body" with "Ralphie the Buffalo is the name of the live mascot of the University of Colorado Buffaloes."
  And I fill in "edit-field-photo-und-0-alt" with "Ralphie Buffalo with handlers"
  And I attach the file "ralphieMtns.jpg" to "edit-field-photo-und-0-upload"
  And I press "edit-field-photo-und-0-upload-button"
  Then I should see "File information"
  And I should see "ralphieMtns.jpg"
  And I should see "Insert"
  And I press "edit-submit"
  Then I should be on "/test-page-one"
  And I should see "Test Page One"
  And I should see "Ralphie the Buffalo is the name of the live mascot of the University of Colorado Buffaloes."

  Scenario: The provide menu link box should be checked on node creation but remain unchecked if user chooses to uncheck that box.
    Given I am logged in as a user with the "site_owner" role
    When I go to "node/add/page"
    And I fill in "edit-title" with "Not In Menu"
    Then the "edit-menu-enabled" checkbox should be checked
    When I uncheck "edit-menu-enabled"
    And I press "Save"
    # ADD CHECK FOR PAGE TITLE
    Then I should see "Not In Menu"
    And I follow "Edit"
    Then the checkbox "edit-menu-enabled" should be unchecked
    And I press "Cancel edit"

  #  6) CHECK SAVE AND ADD ANOTHER
  Scenario: Node Functionality - Create a page node and add another
  Given I am logged in as a user with the "site_owner" role
  And I am on "node/add/page"
  And fill in "edit-title" with "Test Page Two"
  When I press "edit-addanother"
  Then I should be on "/node/add/page"
