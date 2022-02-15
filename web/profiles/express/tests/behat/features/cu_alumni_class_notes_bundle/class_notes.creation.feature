@class_notes
Feature: Class Notes Node Type

When I login to a Web Express website
As an authenticated user with the right permission
I should be able to create a class note node


Scenario Outline: An authenticated user should be able to access the form for adding a class note
    Given  I am logged in as a user with the <role> role
    When I go to "node/add/class-note"
    Then I should see <message>

    Examples:
        | role            | message                  |
        | edit_my_content | "Access Denied"          |
        | edit_only       | "Access Denied"          |
        | site_owner      | "Create Class Note"      |
        | administrator   | "Create Class Note"      |
        | developer       | "Create Class Note"      |

Scenario: An anonymous user should not be able to access the form for adding a class note
    When I am on "node/add/class-note"
    Then I should see "Access denied"
