@cu_content_sequence_bundle
Feature: Content Sequence Block
When I login to a Web Express website
As an authenticated user with the right permission
I should be able to create a content sequence block

Scenario Outline: An authenticated user should be able to access the form for adding a content sequence block
    Given  I am logged in as a user with the <role> role
    When I go to "block/add/content-sequence"
    Then I should see <message>

    Examples:
        | role            | message                         |
        | edit_my_content | "Access Denied"                 |
        | edit_only       | "Access Denied"                 |
        | site_owner      | "Create Content Sequence block" |
        | administrator   | "Create Content Sequence block" |
        | developer       | "Create Content Sequence block" |

Scenario: An anonymous user should not be able to access the form for adding a campus news block
    When I am on "block/add/content-sequence"
    Then I should see "Access denied"
