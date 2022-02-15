@newsArticles
Feature: Article Read More Links

Scenario: An issue page should contain articles with a single read more link
Given I am logged in as a user with the "site_owner" role
And I am on "node/add/article"
And fill in "edit-title" with "Test Article One"
When I press "edit-submit"
Then I should see "Article Test Article One has been created."
Then I go to "node/add/article"
And fill in "edit-title" with "Test Article Two"
When I press "edit-submit"
Then I should see "Article Test Article Two has been created."
Then I go to "article-tests"
And I should see "Article Tests"
And I should see one ".more-link" in ".article-view-mode-teaser"
